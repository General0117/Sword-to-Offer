#include<iostream>
#include<memory.h>
using namespace std;

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

//void _PrintProbability(int number,int* p,int sum,int count)
//{
//    if(number==0)
//    {
//        p[sum-count]++;
//        return;
//    }
//    int i;
//    for(i=1;i<=6;++i)
//    {
//        _PrintProbability(number-1,p,sum+i,count);
//    }
//}
//
//void PrintProbability(int number)
//{
//    if(number<=0)
//        return;
//    int* p=new int[5*number+1];//6*number-number+1
//    memset(p,0,sizeof(int)*(5*number+1));
//    int sum=0;
//    _PrintProbability(number,p,sum,number);
//    int i;
//    for(i=0;i<5*number+1;++i)
//    {
//        cout<<i+number<<" : "<<p[i]<<endl;
//    }
//    delete []p;
//}

void PrintProbability(int number)
{
    if(number<=0)
        return;
    int *p1=new int[number*6+1];
    int *p2=new int[number*6+1];
    memset(p1,0,sizeof(int)*(6*number+1));
    memset(p2,0,sizeof(int)*(6*number+1));
    int i,j,k;
    for(i=1;i<=6;++i)
    {
        p2[i]=1;
    }
    for(i=2;i<=number;++i)
    {
        for(j=0;j<i;++j)
        {
            p1[j]=0;
        }
        for(j=i;j<=6*i;++j)
        {
            p1[j]=0;
            for(k=1;k<=MIN(6,j);++k)
            {
                p1[j]+=p2[j-k];
            }
        }
        swap(p1,p2);
    }
    for(i=number;i<=6*number;++i)
    {
        cout<<i<<" : "<<p2[i]<<endl;
    }
    delete []p1;
    delete []p2;
}

//------测试代码-------
void test()
{
    PrintProbability(10);
}

int main()
{
    test();
    return 0;
}
