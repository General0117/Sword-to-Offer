#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ReplaceBlank(string str)
{
    int i,j;
    int len=str.size();
    for(i=0;i<len;++i)
    {
        if(str[i]==' ')
        {
            len+=2;
            str.resize(len);
            for(j=len-3;j>i;--j)
            {
                str[j+2]=str[j];
            }
            str[i++]='%';
            str[i++]='2';
            str[i]='0';
        }
    }
    return str;
}

//string ReplaceBlank(string str)
//{
//    int len=str.size();
//    if(len==0)
//        return str;
//    int BlankCount=0;
//    int i=0;
//    while(i<len)
//    {
//        if(str[i++]==' ')
//            BlankCount++;
//    }
//    str.resize(len+(BlankCount<<1));
//    int j=str.size()-1;
//    i--;
//    while(i>=0)
//    {
//        if(str[i]!=' ')
//        {
//            str[j--]=str[i--];
//        }
//        else
//        {
//            str[j--]='0';
//            str[j--]='2';
//            str[j--]='%';
//            i--;
//        }
//    }
//    return str;
//}

//-------测试代码-------

void test()
{
    char* carr[]={" hello","world ","You are a good boy","Welcome    to   here","ItIsAStringThatHasNoBlank",""," ","    "};
    vector<string> vs;
    int i;
    for(i=0;i<sizeof(carr)/sizeof(carr[0]);++i)
    {
        vs.push_back(carr[i]);
    }
    for(i=0;i<vs.size();++i)
    {
        cout<<":"<<vs[i]<<":\t->\t:"<<ReplaceBlank(vs[i])<<":"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
