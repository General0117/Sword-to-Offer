#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class DynamicArray{
public:
    void insert(T t)
    {
        if(((min.size()+max.size()) & 0x1)==0)
        {
            if(max.size()>0 && t<max[0])
            {
                max.push_back(t);
                make_heap(max.begin(),max.end(),less<T>());
                t=max[0];
                pop_heap(max.begin(),max.end(),less<T>());
                max.pop_back();
            }
            min.push_back(t);
            make_heap(min.begin(),min.end(),greater<T>());
        }
        else
        {
            if(min.size()>0 && t>min[0])
            {
                min.push_back(t);
                make_heap(min.begin(),min.end(),greater<T>());
                t=min[0];
                pop_heap(min.begin(),min.end(),greater<T>());
                min.pop_back();
            }
            max.push_back(t);
            make_heap(max.begin(),max.end(),less<T>());
        }
    }

    T GetMedian()
    {
        int size=min.size()+max.size();
        if(size==0)
            throw exception();
        T median=0;
        if(size&0x1==1)
            median=min[0];
        else
            median=(min[0]+max[0])/2;
        return median;
    }
private:
    vector<T> min;
    vector<T> max;
};

//------测试代码------
void test()
{
    DynamicArray<int> d;
    int arr[]={1,2,3,4,5,6,7,8,9};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        d.insert(arr[i]);
    }
    cout<<d.GetMedian()<<endl;
}

int main()
{
    test();
    return 0;
}
