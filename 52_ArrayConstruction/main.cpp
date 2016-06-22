#include<iostream>
#include<vector>
using namespace std;

void multiply(const vector<int>& array1,vector<int>& array2)
{
    int length1=array1.size();
    int length2=array2.size();
    int i;
    if(length2>=length1 && length1>=2)//至少2个
    {
        array2[0]=1;
        for(i=1;i<length2;++i)
            array2[i]=array2[i-1]*array1[i-1];
        int tmp=1;
        for(i=length2-2;i>=0;--i)
        {
            tmp*=array1[i+1];
            array2[i]*=tmp;
        }
    }
}

//------测试代码------
void test()
{
    int arr[]={1,2,3,4,5};
    vector<int> array1(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> array2;
    array2.resize(array1.size());
    multiply(array1,array2);
    int i;
    for(i=0;i<array1.size();i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<array2.size();i++)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
