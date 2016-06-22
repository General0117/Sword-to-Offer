#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

//int NumberOf1Between1AndN(unsigned int n)
//{
//    int i;
//    int count=0;
//    int tmp;
//    for(i=1;i<=n;++i)
//    {
//        tmp=i;
//        while(tmp!=0)
//        {
//            if(tmp%10==1)
//                count++;
//            tmp/=10;
//        }
//    }
//    return count;
//}

int NumberOf1(const string str)
{
    int length=str.size();
    if(length<=0)
        return 0;
    int first=str[0]-'0';
    if(length==1 && first==0)
        return 0;
    if(length==1 && first>0)
        return 1;
    int numFirstDigit=0;
    if(first==1)
    {
        numFirstDigit=atoi(str.c_str()+1)+1;
    }
    else if(first>1)
    {
        numFirstDigit=pow(10,length-1);
    }
    int numOtherDigit=first*(length-1)*pow(10,length-2);
    int numRecursive=NumberOf1(str.c_str()+1);
    return numFirstDigit+numOtherDigit+numRecursive;
}

int NumberOf1Between1AndN(unsigned int n)
{
    if(n<=0)
        return 0;
    char str[11];
    sprintf(str,"%d",n);
    return NumberOf1(str);
}

//-------测试代码---------
void test()
{
    int n;
    while(1)
    {
        cin>>n;
        cout<<NumberOf1Between1AndN(n)<<endl;
    }
}

int main()
{
    test();
    return 0;
}
