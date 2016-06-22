#include<iostream>
using namespace std;

//method 1:constructor
//class tmp{
//public:
//    tmp()
//    {
//        sum+=n;
//        n++;
//    }
//    static int sum;
//    static int n;
//};
//int tmp::sum=0;
//int tmp::n=1;
//
//int TestClass(int n)
//{
//    int n;
//    cin>>n;
//    tmp *p=new tmp[n];
//    delete []p;
//    p=NULL;
//    return tmp::sum;
//}

//method 2:virtual function
//class base;
//base* arr[2];
//
//class base{
//public:
//    virtual int fun(int n)
//    {
//        return 0;
//    }
//};
//
//class derive:public base{
//public:
//    int fun(int n)
//    {
//        return arr[!!n]->fun(n-1)+n; 
//    }
//};
//
//int TestVirtualFun(int n)
//{
//    int n;
//    cin>>n;
//    base b;
//    derive d;
//    arr[0]=&b;
//    arr[1]=&d;
//    return d.fun(n);
//}

//method 3:fun pointer
//typedef int (*tfun)(int);
//
//tfun arr[2];
//int FunA(int n)
//{
//    return 0;
//}
//
//int FunB(int n)
//{
//    return arr[!!n](n-1)+n;
//}
//
//int TestFunPointer(int n)
//{
//    int n;
//    cin>>n;
//    arr[0]=FunA;
//    arr[1]=FunB;
//    return FunB(n);
//}

//method 4:template
template<int N>
int fun()
{
    return fun<N-1>()+N;
}

template<>
int fun<1>()
{
    return 1;
}

int TestTemplate()
{
    return fun<100>();
}

//------测试代码------
void test()
{
    //cout<<TestClass()<<endl;
    //cout<<TestVirtualFun()<<endl;
    //cout<<TestFunPointer()<<endl;
    cout<<TestTemplate()<<endl;
}

int main()
{
    test();
    return 0;
}
