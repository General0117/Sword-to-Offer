#include<iostream>
#include<string>
using namespace std;

void ReverseSentence(string& str)
{
    int i,j,tmp;
    for(i=0,j=str.size()-1;i<j;++i,--j)
    {
        swap(str[i],str[j]);
    }
    for(i=0;i<str.size();)
    {
        j=i;
        while(j<str.size() && str[j]!=' ')
            j++;
        tmp=j;
        j--;
        for(;i<j;++i,--j)
            swap(str[i],str[j]);
        while(tmp<str.size() && str[tmp]==' ')
            tmp++;
        i=tmp;
    }
}

//------测试代码------
void test()
{
    string str="I am a student.";
    cout<<str<<endl;
    ReverseSentence(str);
    cout<<str<<endl;
}

int main()
{
    test();
    return 0;
}
