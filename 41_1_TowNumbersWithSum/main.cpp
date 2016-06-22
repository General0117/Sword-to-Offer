#include<iostream>
#include<vector>
using namespace std;

//最简单直接的解法
//bool FindNumbersWithSum(const vector<int>& v,int sum,int& n1,int& n2)
//{
//    int i,j;
//    for(i=0;i<v.size();++i)
//    {
//        for(j=i;j<v.size();++j)
//        {
//            if(v[i]+v[j]==sum)
//            {
//                n1=v[i];
//                n2=v[j];
//                return true;
//            }
//        }
//    }
//    return false;
//}

bool FindNumbersWithSum(const vector<int>& v,int sum,int& n1,int& n2)
{
    int left=0,right=v.size()-1;
    while(left<=right)
    {
        if(v[left]+v[right]==sum)
        {
            n1=v[left];
            n2=v[right];
            return true;
        }
        else if(v[left]+v[right]>sum)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return false;
}

//-----测试代码------
void test()
{
    int arr[]={1,2,4,7,11,15};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int n1,n2;
    int sum=15;
    if(FindNumbersWithSum(v,sum,n1,n2)==true)
    {
        cout<<n1<<"  "<<n2<<endl;
    }
    else
    {
        cout<<"none!"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
