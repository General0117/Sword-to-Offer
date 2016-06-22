#include<iostream>
#include<vector>
using namespace std;

class NoNumIsMoreThanHalf{};

template<typename T>
bool CheckNumIsMoreThanHalf(const vector<T>& v,const T& num)
{
    int i;
    int time=0;
    for(i=0;i<v.size();++i)
    {
        if(v[i]==num)
            time++;
    }
    if(time>v.size()/2)
        return true;
    else
        return false;
}

//template<typename T>
//int Partition(vector<T>& v,int left,int right)
//{
//    int i=left,j=right-1;
//    T tmp=v[left];
//    while(i<j)
//    {
//        while(i<j && v[i]<=tmp)
//            i++;
//        swap(v[i],v[j]);
//        while(i<j && v[j]>=tmp)
//            j--;
//        swap(v[i],v[j]);
//    }
//    return i;
//}
//
//template<typename T>
//T _MoreThanHalfNum(vector<T>& v,int left,int right)throw (NoNumIsMoreThanHalf)
//{
//    int mid=Partition(v,left,right);
//    if(mid==v.size()/2)
//    {
//        if(CheckNumIsMoreThanHalf(v,mid))
//            return v[mid];
//        else
//            throw NoNumIsMoreThanHalf();
//    }
//    else if(mid<v.size()/2)
//        return _MoreThanHalfNum(v,mid+1,right);
//    else
//        return _MoreThanHalfNum(v,left,mid);
//}
//
//template<typename T>
//T MoreThanHalfNum(vector<T>& v)
//{
//    _MoreThanHalfNum(v,0,v.size());
//}

template<typename T>
T MoreThanHalfNum(const vector<T>& v)
{
    if(v.size()==0)
        throw NoNumIsMoreThanHalf();
    T num=v[0];
    int time=1;
    int i;
    for(i=1;i<v.size();++i)
    {
        if(time>0)
        {
            if(v[i]==num)
            {
                time++;
            }
            else
            {
                time--;
            }
        }
        else
        {
            num=v[i];
            time=1;
        }
    }
    if(CheckNumIsMoreThanHalf(v,num))
        return num;
    else
        throw NoNumIsMoreThanHalf();
}

//------测试代码------
void test()
{
    //int arr[]={1,2,3,2,2,2,5,4,2};
    int arr[]={1,2,3,2,2,2,5,4,2};
    vector<int> v;
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    try
    {
        cout<<MoreThanHalfNum(v)<<endl;
    }
    catch(NoNumIsMoreThanHalf&)
    {
        cout<<"Has No Num Is More Than Half of Array!"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
