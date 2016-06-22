#include<iostream>
#include<string>
using namespace std;

void LeftRotateString(string& str,int n)
{
    if(n<=0)
        return;
    n%=str.size();
    int i,j;
    for(i=0,j=str.size()-1;i<j;++i,--j)
        swap(str[i],str[j]);
    i=0,j=str.size()-n-1;
    while(i<j)
        swap(str[i++],str[j--]);
    i=str.size()-n,j=str.size()-1;
    while(i<j)
        swap(str[i++],str[j--]);
}

//------测试代码------
void test()
{
    string str="abcdefg";
    cout<<str<<endl;
    LeftRotateString(str,2);
    cout<<str<<endl;
}

int main()
{
    test();
    return 0;
}
