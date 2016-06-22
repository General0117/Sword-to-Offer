#include<iostream>
#include<stack>
using namespace std;

class StackIsEmpty{};

template<typename T>
class MyStack{
public:
    void push(const T& t)
    {
        if(s.empty())
        {
            m.push(t);
        }
        else
        {
            if(t<m.top())
            {
                m.push(t);
            }
            else
            {
                m.push(m.top());
            }
        }
        s.push(t);
    }
    void pop()
    {
        if(!s.empty())
        {
            s.pop();
            m.pop();
        }
        else
            throw StackIsEmpty();
    }
    T& min()
    {
        if(!s.empty())
        {
            return m.top();
        }
        else
            throw StackIsEmpty();
    }
    bool empty()
    {
        return s.empty();
    }
private:
    stack<T> s;
    stack<T> m;//min
};

//--------测试代码--------

void test()
{
    int arr[]={2,3,1,4,0};
    int i;
    MyStack<int> s;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        s.push(arr[i]);
        cout<<"push: "<<arr[i]<<"\tmin: "<<s.min()<<endl;
    }
    while(!s.empty())
    {
        cout<<"min: "<<s.min()<<"\tpop!"<<endl;
        s.pop();
    }
}

int main()
{
    test();
    return 0;
}
