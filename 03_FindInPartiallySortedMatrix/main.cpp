//
//Author:SmartBrave
//

#include<iostream>
#include<vector>
using namespace std;

//二分法
//bool _find(const vector<vector<int> >& matrix,int startm,int startn,int endm,int endn,int x)
//{
//    if(matrix.size()==0 || startm>endm || startn>endn)
//        return false;
//    int leftn=startn,leftm=startm,rightn=endn,rightm=endm;
//    int midn,midm;
//    while(leftn<=rightn && leftm<=rightm)
//    {
//        midn=leftn+(rightn-leftn)/2;
//        midm=leftm+(rightm-leftm)/2;
//        if(matrix[midn][midm]==x)
//            return true;
//        else if(matrix[midn][midm]>x)
//        {
//            if(matrix[midn][leftm]>x ||matrix[leftn][midm]>x)
//            {
//                rightn=midn-1;
//                rightm=midm-1;
//            }
//            else if(_find(matrix,leftm,midn,midm,midn,x) || _find(matrix,midm,leftn,midm,midn,x))
//                return true;
//            else
//                return false;
//        }
//        else
//        {
//            int tmpm=midm,tmpn=midn;
//            leftm=midm+1;
//            leftn=midn;
//            if(_find(matrix,midm+1,midn,rightm,rightn,x) || _find (matrix,leftm,midn+1,rightm,rightn,x) || _find(matrix,midm+1,midn+1,rightm,rightn,x))
//                return true;
//            else
//                return false;
//        }
//    }
//    return false;
//}
//bool find(const vector<vector<int> >& matrix,int x)
//{
//    if(matrix.size()==0)
//        return false;
//    return _find(matrix,0,0,matrix[0].size()-1,matrix.size()-1,x);
//}

bool find(const vector<vector<int> >& matrix,int x)
{
    if(matrix.size()==0)
        return false;
    size_t row=matrix.size();
    int i=0,j=matrix[0].size()-1;
    while(i<row && j>=0)
    {
        if(matrix[i][j]==x)
            return true;
        else if(matrix[i][j]<x)
            i++;
        else
            j--;
    }
    return false;
}

//---------测试代码-----------

void test()
{
    //int arr[5][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9}};
    //int x[]={0,1,2,5,6,9,10};
    int arr[][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    int x[]={1,15,4,20,0,3};
    //测试用例
    //二维数组中包含查找的数字(查找的数字是数组中的最大值，最小值，介于二者之间)
    //二维数组中没有查找的数字(查找的数字大于数组中最大值，小于最小值，介于二者之间但没有这个数字)
    //特殊输入(二维数组为空)
    vector<int> v;
    vector<vector<int> > vv;
    if(find(vv,2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            v.push_back(arr[i][j]);
        }
        vv.push_back(v);
        v.clear();
    }
    for(i=0;i<sizeof(x)/sizeof(x[0]);++i)
    {
        if(find(vv,x[i]))
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
