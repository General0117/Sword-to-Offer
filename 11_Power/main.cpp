#include<iostream>
#include<stdio.h>
using namespace std;

class DevidedByZero{};

double Power(double base,int exponent) throw (DevidedByZero)
{
    double result=1;
    if(exponent>=0)
    {
        for(int i=0;i<exponent;++i)
        {
            result*=base;
        }
    }
    else
    {
        for(int i=0;i<(-exponent);++i)
        {
            result*=base;
        }
        if(result!=0)
            result=1/result;
        else
            throw DevidedByZero();
    }
    return result;
}


//-------测试代码---------
void test()
{
    double base;
    int exponent;
    base=1.5;
    exponent=2;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=1.5;
    exponent=-2;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=1.5;
    exponent=0;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=-1.5;
    exponent=3;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=-1.5;
    exponent=-3;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=-1.5;
    exponent=0;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=0.0;
    exponent=2;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=0.0;
    exponent=-2;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }

    base=0.0;
    exponent=0;
    try
    {
        printf("base: %f,exponent: %d,result: %f\n",base,exponent,Power(base,exponent));
    }
    catch(const DevidedByZero&)
    {
        printf("base: %f,exponent: %d is error!\n");
    }
}

int main()
{
    test();
    return 0;
}
