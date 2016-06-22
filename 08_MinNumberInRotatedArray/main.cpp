#include<iostream>
#include<vector>
using namespace std;

int MinInOrder(vector<int> arr)
{
    if(arr.size()<=0)
        return -1;
    int min=0;
    int i;
    for(i=0;i<arr.size();++i)
    {
        if(arr[i]<arr[min])
            min=i;
    }
    return arr[min];
}

int Min(vector<int> arr)
{
    int left=0,right=arr.size()-1;
    int mid;
    if(arr[left]<arr[right])
        return left;
    while(left<right-1)
    {
        if(right-left==1)
        {
            mid=right;
            break;
        }
        mid=left+(right-left)/2;
        if(arr[mid]==arr[left] && arr[mid]==arr[right])
            return MinInOrder(arr);
        if(arr[mid]<=arr[right])
            right=mid;
        else if(arr[mid]>=arr[left])
            left=mid;
    }
    return arr[mid];
}

//-------测试代码--------
void test()
{
    //int arr[]={0,1,2,3,4,5,6,7,8,9};
    int arr[]={3,4,5,5,6,7,8,9,0,1,2,};
    //int arr[]={1};
    vector<int> v;
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    cout<<Min(v)<<endl;
}

int main()
{
    test();
    return 0;
}
