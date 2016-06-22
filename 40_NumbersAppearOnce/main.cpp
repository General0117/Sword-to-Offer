#include<iostream>
#include<vector>
using namespace std;

int FindFirstBitIs1(int num)
{
    int i,index=1;
    for(i=0;i<8*sizeof(int);++i)
    {
        if((num & (index<<i)) ==0)
            continue;
        else
            break;
    }
    return i;
}

bool IsBit1(int num,int pos)
{
    return num&(1<<pos);
}

void FindNumbersAppearOnce(const vector<int>& v,int& n1,int& n2)
{
    int i,res=0;
    for(i=0;i<v.size();++i)
    {
        res^=v[i];
    }
    int n=FindFirstBitIs1(res);
    n1=n2=0;
    for(i=0;i<v.size();++i)
    {
        if(IsBit1(v[i],n))
        {
            n1^=v[i];
        }
        else
        {
            n2^=v[i];
        }
    }
}

//-----测试代码-------
void test()
{
    int arr[]={2,4,3,6,3,2,5,5};
    int n1,n2;
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    FindNumbersAppearOnce(v,n1,n2);
    cout<<n1<<"  "<<n2<<endl;
}

int main()
{
    test();
    return 0;
}

