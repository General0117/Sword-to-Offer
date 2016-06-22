#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool IsPopOrder(const vector<int>& pPush,const vector<int>& pPop)
{
    int i,j;
    int length=pPush.size();
    if(length==0)
        return true;
    stack<char> s;
    s.push(pPush[0]);
    i=1,j=0;
    while(i<=length && j<length)
    {
        if(s.top()!=pPop[j] && i==length)
            return false;
        if(s.top()!=pPop[j])
        {
            s.push(pPush[i++]);
        }
        else if(s.top()==pPop[j])
        {
            s.pop();
            j++;
        }
    }
    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-------测试代码-------

void test()
{
    int arr_push[]={1,2,3,4,5};
    int arr_pop1[]={4,5,3,2,1};
    int arr_pop2[]={4,3,5,1,2};
    vector<int> push;
    vector<int> pop1;
    vector<int> pop2;
    int i;
    for(i=0;i<sizeof(arr_push)/sizeof(arr_push[0]);++i)
    {
        push.push_back(arr_push[i]);
        pop1.push_back(arr_pop1[i]);
        pop2.push_back(arr_pop2[i]);
    }
    if(IsPopOrder(push,pop1))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    if(IsPopOrder(push,pop2))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
