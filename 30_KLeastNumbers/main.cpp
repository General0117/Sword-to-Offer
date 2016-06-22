#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

//排序
//template<typename T>
//vector<T> GetLeastNumbers(vector<T> v,int k)
//{
//    if(k>v.size())
//        return v;
//    sort(v.begin(),v.end());
//    return vector<T>(v.begin(),v.begin()+k);
//}

//快速排序的partition
//template<typename T>
//void Partition(vector<T>& v,int left,int right,int k)
//{
//    if(left>=right-1)
//        return;
//    T tmp=v[left];
//    int i=left,j=right-1;
//    while(i<j)
//    {
//        while(i<j && v[j]>=tmp)
//            j--;
//        swap(v[i],v[j]);
//        while(i<j && v[i]<=tmp)
//            i++;
//        swap(v[i],v[j]);
//    }
//    if(i==k)
//        return;
//    else if(i<k)
//        Partition(v,i+1,right,k);
//    else
//        Partition(v,left,i,k);
//}
//
//template<typename T>
//vector<T> GetLeastNumbers(vector<T> v,int k)
//{
//    if(k>v.size())
//        return v;
//    Partition(v,0,v.size(),k);
//    return vector<T>(v.begin(),v.begin()+k);
//}

//堆或红黑树
//template<typename T>
//vector<T> GetLeastNumbers(vector<T> v,int k)
//{
//    //堆
//    if(k>v.size())
//        return v;
//    make_heap(v.begin(),v.begin()+k);
//    int i;
//    for(i=k;i<v.size();++i)
//    {
//        if(v[i]>v[0])
//            continue;
//        else
//        {
//            swap(v[i],v[0]);
//            make_heap(v.begin(),v.begin()+k);
//        }
//    }
//    return vector<T>(v.begin(),v.begin()+k);
//}
template<typename T>
vector<T> GetLeastNumbers(vector<T> v,int k)
{
    //红黑树
    if(k>v.size())
        return v;
    multiset<T> ms;
    int i;
    for(i=0;i<v.size();++i)
    {
        if(ms.size()<k)
        {
            ms.insert(v[i]);
        }
        else
        {
            if(v[i]<*ms.begin())
            {
                ms.erase(ms.begin());
                ms.insert(v[i]);
            }
        }
        typename multiset<T>::iterator it=ms.begin();
    }
    return vector<T>(ms.begin(),ms.end());
}

//------测试代码------
void test()
{
    int arr[]={8,4,5,1,6,2,7,3};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int i,j;
    vector<int> res;
    for(j=0;j<=v.size();++j)
    {
        res=GetLeastNumbers(v,j);
        for(i=0;i<res.size();++i)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    test();
    return 0;
}
