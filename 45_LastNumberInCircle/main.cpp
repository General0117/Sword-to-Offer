#include<iostream>
#include<list>
using namespace std;

//int LastRemaining(unsigned int n,unsigned int m)
//{
//    int i;
//    list<int> mylist;
//    for(i=0;i<n;++i)
//    {
//        mylist.push_back(i);
//    }
//    list<int>::iterator iter=mylist.begin();
//    while(mylist.size()!=1)
//    {
//        for(i=0;i<m-1;++i)
//        {
//            iter++;
//            if(iter==mylist.end())
//                iter=mylist.begin();
//        }
//        list<int>::iterator tmp=--iter;
//        iter++;
//        mylist.erase(iter);
//        iter=tmp;
//    }
//    return *mylist.begin();
//}

int LastRemaining(unsigned int n,unsigned int m)
{
    if(n<1 || m<1)
        return -1;
    if(n==1)
        return 0;
    int last=0;
    int i;
    for(i=2;i<=n;++i)
    {
        last=(last+m)%i;
    }
    return last;
}

//-----测试代码-------
void test()
{
    cout<<LastRemaining(5,3)<<endl;
}

int main()
{
    test();
    return 0;
}
