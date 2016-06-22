#include<iostream>
#include<vector>
using namespace std;

//error
//int FindGreatestSumOfSubArray(matrixector<int> v)throw (exception)
//{
//    if(v.size()<=0)
//        throw new exception();
//    int CurSum=0,PrevSum=0;
//    int i;
//    for(i=0;i<v.size();++i)
//    {
//        if(i==0 || (i!=0 && v[i]<0 && v[i-1]>=0))
//        {
//            PrevSum=CurSum;
//        }
//        CurSum+=v[i];
//        if(i==0 || (i!=0 && v[i]>0 && v[i-1]<=0))
//        {
//            if(CurSum>PrevSum)
//            {
//                PrevSum=CurSum;
//            }
//            else
//            {
//                PrevSum=0;
//            }
//        }
//    }
//    return PrevSum;
//}

//分治法
int _FindMaxCrossSumArray(vector<int> v,int left,int mid,int right)
{
    int LeftSum=-2147483647,RightSum=-2147483647;
    int LeftPos,RightPos;
    int Sum=0;
    int i;
    for(i=mid;i>=left;--i)
    {
        Sum+=v[i];
        if(Sum>LeftSum)
        {
            LeftSum=Sum;
            LeftPos=i;
        }
    }
    Sum=0;
    for(i=mid+1;i<=right;++i)
    {
        Sum+=v[i];
        if(Sum>RightSum)
        {
            RightSum=Sum;
            RightPos=i;
        }
    }
    Sum=0;
    for(i=LeftPos;i<=RightPos;++i)
    {
        Sum+=v[i];
    }
    return Sum;
}

int _FindGreatestSumOfSubArray(vector<int> v,int left,int right)
{
    if(left>=right)
        return v[left];
    int mid=left+(right-left)/2;
    int LeftSum=_FindGreatestSumOfSubArray(v,left,mid);
    int RightSum=_FindGreatestSumOfSubArray(v,mid+1,right);
    int MidSum=_FindMaxCrossSumArray(v,left,mid,right);
    if(LeftSum>=RightSum && LeftSum>=MidSum)
        return LeftSum;
    else if(RightSum>=LeftSum && RightSum>=MidSum)
        return RightSum;
    else
        return MidSum;
}

int FindGreatestSumOfSubArray(vector<int> v)
{
    if(v.size()<=0)
        throw new exception();
    return _FindGreatestSumOfSubArray(v,0,v.size()-1);
}

//动态规划
//error
//如果数组中全为负数，则返回0(子数组为空)
//int _FindGreatestSumOfSubArray(vector<int> v,int cur,int& MaxSum,bool& IsContinuous)
//{
//    if(cur==0)
//    {
//        IsContinuous=true;
//        return v[cur];
//    }
//    int sum=_FindGreatestSumOfSubArray(v,cur-1,MaxSum,IsContinuous);
//    if(v[cur]<0)
//    {
//        if(sum<=0)
//        {
//            IsContinuous=false;
//            MaxSum=0;
//            return 0;
//        }
//        else
//        {
//            if(sum+v[cur]>0)
//            {
//                IsContinuous=true;
//            }
//            else
//            {
//                IsContinuous=false;
//            }
//            if(sum>MaxSum)
//                MaxSum=sum;
//            return MaxSum;
//        }
//    }
//    else
//    {
//        if(sum<=0)
//        {
//            MaxSum=v[cur];
//        }
//        else
//            MaxSum=v[cur]+sum;
//        return MaxSum;
//    }
//}
//
//int FindGreatestSumOfSubArray(vector<int> v)
//{
//    if(v.size()<=0)
//        throw new exception();
//    if(v.size()==1)
//        return v[0];
//    int MaxSum=0;
//    bool IsContinuous;
//    int sum=_FindGreatestSumOfSubArray(v,v.size()-1,MaxSum,IsContinuous);
//    return MaxSum;
//}

//------测试代码------
void test()
{
    //int arr[]={1,-2,3,10,-4,7,2,-5};
    int arr[]={6,-7,2};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<FindGreatestSumOfSubArray(v)<<endl;
}

int main()
{
    test();
    return 0;
}
