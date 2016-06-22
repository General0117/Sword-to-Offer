#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool IsContinuous(vector<int> v)
{
    sort(v.begin(),v.end());
    int NumberOf0=0;
    int i;
    int tmp;
    int space=0;
    for(i=0;i<v.size();++i)
    {
        if(v[i]==0)
            NumberOf0++;
        else
        {
            if(i>0 && v[i-1]==0)
                tmp=v[i];
            else if(i==0)
                tmp==v[i];
            else if(tmp==v[i-1]+1)
            {
                tmp=v[i];
                continue;
            }
            else if(v[i]==v[i-1])
                return false;
            else
            {
                tmp=v[i];
                space=v[i]-v[i-1];
            }
        }
    }
    if(NumberOf0>=space)
        return true;
    else
        return false;
}

//------测试代码------
void test()
{
    //int arr[]={0,1,3,4,5};//0代表大小王
    //int arr[]={1,3,4,5,6};
    //int arr[]={1,3,4,0,0};
    int arr[]={1,3,4,4,0};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    if(IsContinuous(v))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}

int main()
{
    test();
    return 0;
}
