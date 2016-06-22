//
//Author:SmartBrave
//

#include<iostream>
#include<vector>
using namespace std;

//version 1
//递归解法，时间复杂度为O(2^n)
//空间复杂度为O(n)
//long long Fib(int x,unsigned long long int& count)
//{
//    count++;
//    if(x==0 || x==1)
//        return x;
//    return Fib(x-1,count)+Fib(x-2,count);
//}

//version 2
//迭代解法，时间复杂度O(n),空间复杂度O(1)
//long long Fib(int x,unsigned long long int& count)
//{
//    if(x<=1)
//        return x;
//    int a=0,b=1,res;
//    int i;
//    for(i=0;i<x-1;++i)
//    {
//        count++;
//        res=a+b;
//        a=b;
//        b=res;
//    }
//    return res;
//}

//version 3
//矩阵解法，时间复杂度O(log n),空间复杂度O(1)
vector<vector<unsigned long long int> > MultiMatrix(vector<vector<unsigned long long int> > matrix1,vector<vector<unsigned long long int> > matrix2)
{
    if(matrix1.size()<=0 || matrix2.size()<=0)
        return vector<vector<unsigned long long int> >();
    vector<vector<unsigned long long int> > res;
    int i,j,k;
    res.resize(matrix1.size());
    for(i=0;i<matrix1.size();++i)
    {
        res[i].resize(matrix2[0].size());
        for(j=0;j<matrix2[0].size();++j)
        {

            res[i][j]=0;
            for(k=0;k<matrix2.size();++k)
            {
                res[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    return res;
}

vector<vector<unsigned long long int> > calc(vector<vector<unsigned long long int> > matrix,int x,unsigned long long int& count)
{
    //have some bug to fix
    //count++;
    //if(x==1)
    //    return matrix;
    //else if(x&1==0)//偶数
    //    return calc(MultiMatrix(matrix,matrix),/*x>>1*/x/2,count);
    //else//奇数
    //    return MultiMatrix(matrix,calc(MultiMatrix(matrix,matrix),/*(x-1)>>1*/(x-1)/2,count));

    //correct
    int i;
    vector<vector<unsigned long long int> > res=matrix;
    for(i=0;i<x-1;++i)
    {
        res=MultiMatrix(matrix,res);
        count++;
    }
    return res;
}

unsigned long long int Fib(int x,unsigned long long int& count)
{
    if(x==0 || x==1)
        return x;
    vector<vector<unsigned long long int> >matrix;
    matrix.resize(2);
    matrix[0].resize(2);
    matrix[1].resize(2);
    matrix[0][0]=matrix[0][1]=matrix[1][0]=1;
    matrix[1][1]=0;
    return calc(matrix,x-1,count)[0][0];
}

//------测试代码------

void test()
{
    unsigned long long int count=0;
    int tmp;
    while(1)
    {
        cout<<"scanf:";
        cin>>tmp;
        count=0;
        cout<<Fib<10>(tmp,count)<<endl;
       //cout<<count<<endl;
    }
}

int main()
{
    test();
    return 0;
}
