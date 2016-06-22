#include<iostream>
#include<vector>
using namespace std;

template<typename T>
int _GetLeft(const vector<T>& v,int left,int right,const T& k)
{
    if(left==right)
        return right;
    int mid=left+(right-left)/2;
    if(v[mid]==k)
        return _GetLeft(v,left,mid,k);
    else
        return _GetLeft(v,mid+1,right,k);
}

template<typename T>
int _GetRight(const vector<T>& v,int left,int right,const T& k)
{
    if(left==right)
        return left;
    if(left==right-1)
    {
        if(v[left]==k)
            return left;
        else
            return right;
    }
    int mid=left+(right-left)/2;
    if(v[mid]==k)
        return _GetRight(v,mid,right,k);
    else
        return _GetRight(v,left,mid-1,k);
}

template<typename T>
int _NumberOfK(const vector<T>& v,int left,int right,const T& k)
{
    if(left>right)
        return 0;
    int mid=left+(right-left)/2;
    if(v[mid]>k)
        return _NumberOfK(v,left,mid-1,k);
    else if(v[mid]<k)
        return _NumberOfK(v,mid+1,right,k);
    else
    {
        int r=_GetRight(v,mid,right,k);
        int l=_GetLeft(v,left,mid,k);
        //cout<<l<<" "<<r<<endl;
        return r-l+1;
    }
}

template<typename T>
int NumberOfK(const vector<T>& v,const T& k)
{
    return _NumberOfK(v,0,v.size()-1,k);
}

//------测试代码--------
void test()
{
    int arr[]={0,1,2,2,3,3,3,4,5,5,6,7,7,7,7,7,7,8};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<NumberOfK(v,0)<<endl;
    cout<<NumberOfK(v,1)<<endl;
    cout<<NumberOfK(v,2)<<endl;
    cout<<NumberOfK(v,3)<<endl;
    cout<<NumberOfK(v,4)<<endl;
    cout<<NumberOfK(v,5)<<endl;
    cout<<NumberOfK(v,6)<<endl;
    cout<<NumberOfK(v,7)<<endl;
    cout<<NumberOfK(v,8)<<endl;
    cout<<NumberOfK(v,10)<<endl;
}

int main()
{
    test();
    return 0;
}
