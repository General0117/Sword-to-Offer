#include<iostream>
using namespace std;

//version 1
//regular method
int NumberOf1(int n)
{
    int count=0;
    while(n)
    {
        if(n&0x1!=0)
        {
            count++;
        }
        n>>=1;
    }
    return count;
}

//version 2
//better method
int NubmerOf1(int n)
{
    int count=0;
    while(n)
    {
        n&=(n-1);
        count++;
    }
}


//-------测试代码--------

void test()
{
    int i;
    for(i=0;i<10;++i)
        cout<<i<<":"<<NumberOf1(i)<<endl;
}
int main()
{
    test();
    return 0;
}
