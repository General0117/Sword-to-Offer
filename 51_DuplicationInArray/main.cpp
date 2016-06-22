#include<iostream>
#include<vector>
using namespace std;

int duplicate(vector<int> v)
{
    int i;
    int length=v.size();
    for(i=0;i<length;++i)
    {
        if(v[i]==i)
            continue;
        else
        {
            while(v[i]!=i)
            {
                if(v[i]==v[v[i]])
                    return v[i];
                swap(v[i],v[v[i]]);
            }
        }
    }
}

//------测试代码-------
void test()
{
    int arr[]={2,3,1,0,2,5,3};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<duplicate(v)<<endl;
}

int main()
{
    test();
    return 0;
}
