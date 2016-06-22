#include<iostream>
using namespace std;

class A{
private:
    A(){}
    ~A(){}
public:
    A* Get()
    {
        return new A;
    }
    void release()
    {
        delete this;
    }
};

class B:public A{
};

//------测试代码------
void test()
{
    A* p=NULL;
    p=p->Get();
    cout<<p<<endl;
    p->release();
    B b;//只声明B而不定义其实例的话，编译器会优化掉，导致人误以为A可以被继承
}

int main()
{
    test();
    return 0;
}
