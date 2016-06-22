#include<iostream>
using namespace std;

int Add(int num1,int num2)
{
    //int sum=num1 ^ num2;
    //int carry=(num1 & num2)<<1;
    //if(carry!=0)
    //    return Add(sum,carry);
    //else
    //    return sum;

    int sum,carry;
    do
    {
        sum=num1 ^ num2;
        carry=(num1 & num2)<<1;
        
        num1=sum;
        num2=carry;
    }while(num2!=0);
    return num1;
}

//------测试代码-------
void test()
{
    int num1=10;
    int num2=20;
    cout<<Add(num1,num2)<<endl;
}

int main()
{
    test();
    return 0;
}
