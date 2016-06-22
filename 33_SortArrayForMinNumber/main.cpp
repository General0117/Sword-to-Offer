#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

//version 1:求出全排列
//string split(const vector<int>& v)
//{
//    if(v.size()==0)
//        return string();
//    char tmp[11];
//    string str;
//    int i;
//    for(i=0;i<v.size();++i)
//    {
//        sprintf(tmp,"%d",v[i]);
//        str+=tmp;
//    }
//    return str;
//}
//
//void PrintMinNumber(vector<int> v)
//{
//    sort(v.begin(),v.end());
//    vector<string> vs;
//    do
//    {
//        vs.push_back(split(v));
//    }while(next_permutation(v.begin(),v.end()));
//    sort(vs.begin(),vs.end());
//    cout<<vs[0]<<endl;
//}

//version 2: 利用字符串比较
bool compair(const string& s1,const string& s2)
{
    string news1=s1+s2;
    string news2=s2+s1;
    int ret=strcmp(news1.c_str(),news2.c_str());
    if(ret<=0)
        return true;
    else
        return false;
}

void PrintMinNumber(vector<int> v)
{
    if(v.size()==0)
        return;
    vector<string> vs;
    char tmp[11];
    int i;
    for(i=0;i<v.size();++i)
    {
        sprintf(tmp,"%d",v[i]);
        vs.push_back(string(tmp));
    }
    sort(vs.begin(),vs.end(),compair);
    for(i=0;i<vs.size();++i)
    {
        cout<<vs[i];
    }
    cout<<endl;
    return;
}

//-------测试代码----------
void test()
{
    int arr[]={3,32,321};
    //int arr[]={3,4,5,2,1};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    PrintMinNumber(v);
}

int main()
{
    test();
    return 0;
}
