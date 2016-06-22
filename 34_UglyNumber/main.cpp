#include<iostream>
#include<vector>
using namespace std;

//bool IsUglyNumber(int n)
//{
//    while(n%2==0)
//        n/=2;
//    while(n%3==0)
//        n/=3;
//    while(n%5==0)
//        n/=5;
//    if(n!=1)
//        return false;
//    return true;
//}
//
//int GetUglyNumber(int index)
//{
//    if(index<=0)
//        return -1;
//    int i=1;
//    int count=0;
//    while(true)
//    {
//        if(IsUglyNumber(i))
//            count++;
//        if(count==index)
//            return i;
//        i++;
//    }
//}

int Min(int a,int b,int c)
{
    int min=a>b?b:a;
    min=min>c?c:min;
    return min;
}

int GetUglyNumber(int index)
{
    if(index<=0)
        return 0;
    vector<int> v;
    v.push_back(1);
    int M2=0,M3=0,M5=0;
    while(v.size()<index)
    {
        int min=Min(v[M2]*2,v[M3]*3,v[M5]*5);
        v.push_back(min);
        while(v[M2]*2<=v[v.size()-1])
            M2++;
        while(v[M3]*3<=v[v.size()-1])
            M3++;
        while(v[M5]*5<=v[v.size()-1])
            M5++;
    }
    return v[v.size()-1];
}

//------测试代码-----
void test()
{
    int n;
    while(true)
    {
        cout<<"Please inter:";
        cin>>n;
        cout<<GetUglyNumber(n)<<endl;
    }
}

int main()
{
    test();
    return 0;
}
