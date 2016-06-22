#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class Queue{
public:
    Queue()
    {}
    ~Queue()
    {}
    bool push(const T& t)
    {
        s1.push(t);
    }
    T front()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty())
        {
            T tmp=s2.top();
            s2.pop();
            return tmp;
        }
    }
private:
    stack<T> s1;
    stack<T> s2;
};

//-------测试代码-------

void test()
{
    Queue<int> q;
    int arr[]={1,2,3,4,5,6,7,8,9};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        q.push(arr[i]);
    }
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        cout<<q.front()<<" ";
    }
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
