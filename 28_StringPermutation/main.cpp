#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//STL
//void Permutation(string str)
//{
//    sort(str.begin(),str.end());
//    do{
//        cout<<str<<endl;
//    }while(next_permutation(str.begin(),str.end()));
//}

void _Permutation(string str,int start,int end)
{
    if(start>=end)
        cout<<str<<endl;
    else
    {
        int i=start;
        for(i=start;i<end;++i)
        {
            swap(str[i],str[start]);
            _Permutation(str,start+1,end);
            swap(str[i],str[start]);
        }
    }
}

void Permutation(string str)
{
    if(str.size()<=0)
        return;
    _Permutation(str,0,str.size());
}

//-------测试代码--------
void test()
{
    string str="abc";
    Permutation(str);
}

int main()
{
    test();
    return 0;
}
