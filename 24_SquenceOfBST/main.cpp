#include<iostream>
#include<vector>
using namespace std;

class ArgIsError{};

template<typename T>
bool compair(const T& t1,const T& t2)
{
    return t1>t2;
}

template<typename T>
bool IsMax(const vector<T>& v,int start,int end,const T& t)throw (ArgIsError)
{
    if(v.size()<=0 || start>end)
        throw ArgIsError();
    int i;
    for(i=start;i<end;++i)
    {
        if(compair(v[i],t))
            return false;
    }
    return true;
}
template<typename T>
bool IsMin(const vector<T>& v,int start,int end,const T& t)throw (ArgIsError)
{
    if(v.size()<=0 || start>end)
        throw ArgIsError();
    int i;
    for(i=start;i<end;++i)
    {
        if(!compair(v[i],t))
            return false;
    }
    return true;
}

template<typename T>
bool VerifySquenceOfBST(const vector<T>& sequence)
{
    if(sequence.size()<=0)
        return true;
    int left=0,right=0;
    int length=sequence.size();
    int i;
    for(i=length-2;i>=0;--i)
    {
        if(sequence[i]<sequence[length-1])
        {
            left=0;
            right=i+1;
            break;
        }
    }
    try
    {
        if(!IsMax(sequence,left,right,sequence[length-1]) || !IsMin(sequence,right,length-1,sequence[length-1]))
        {
            return false;
        }
    }
    catch(ArgIsError&)
    {
        ;
    }
    vector<T> lseq(sequence.begin()+left,sequence.begin()+right),rseq(sequence.begin()+right,sequence.begin()+length-1);
    if(VerifySquenceOfBST(lseq) && VerifySquenceOfBST(rseq))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----测试代码------
void test()
{
    //int arr[]={5,7,6,9,11,10,8};//对应一颗满二叉搜索树
    int arr[]={7,4,6,5};//没有对应的二叉搜索树
    //int arr[]={2,5,4,8,9,7};//完全二叉树
    //int arr[]={5,4,3,2,1};//所有节点都没有左子树
    //int arr[]={1,2,3,4,5};//所有节点都没有右子树
    //int arr[]={5};//只有一个节点
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    int i;
    if(VerifySquenceOfBST(v))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
