#include<iostream>
#include<pthread.h>
using namespace std;

//单例模式类包含的数据
typedef struct data{
    int a;
    //other
}data;

//同步锁，防止了在多线程程序中可能出现的问题
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

class singleton{
public:
    data* create(int x)
    {
        pthread_mutex_lock(&lock);
        if(instance==NULL)
        {
            instance=new data;
            instance->a=x;
            //DoOtherThing
        }
        pthread_mutex_unlock(&lock);
        return instance;
    }
    void print()
    {
        if(instance!=NULL)
            cout<<instance->a<<endl;
        else
            cout<<"NULL"<<endl;
    }
    ~singleton()
    {
        if(instance!=NULL)
        {
            delete instance;
        }
    }
private:
    singleton()
    {}
    singleton(const singleton& s)
    {}
    
private:
    static data* instance;
};
data* singleton::instance=NULL;


//-------测试代码--------
void test()
{
    singleton* ps;
    ps->create(10);
    ps->print();
    singleton* ps1;
    ps1->create(20);
    ps1->print();
}

int main()
{
    test();
    return 0;
}

