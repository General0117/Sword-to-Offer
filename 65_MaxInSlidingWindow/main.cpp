#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& num,unsigned int size)
{
    vector<int> maxInWindows;
    if(size <= num.size() && size>=1)
    {
        deque<int> q;
        int i;
        for(i=0;i<size;++i)
        {
            while(!q.empty() && num[q.back()]<=num[i])
                q.pop_back();
            q.push_back(i);
        }
        for(;i<num.size();++i)
        {
            maxInWindows.push_back(num[q.front()]);
            while(!q.empty() && num[q.back()]<=num[i])
                q.pop_back();
            if(!q.empty() && q.front()<=(i-size))
                q.pop_front();
            q.push_back(i);
        }
        maxInWindows.push_back(num[q.front()]);
    }
    return maxInWindows;
}

//------测试代码------
void test()
{
    int arr[]={2,3,4,2,6,2,5,1};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int size=3;
    v=maxInWindows(v,size);
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
