#include<iostream>
#include<vector>
using namespace std;

void PrintMatrixClockwisely(const vector<vector<int> >& matrix)
{
    if(matrix.size()<=0)
        return;
    int up=0,down=matrix.size(),left=0,right=matrix[0].size();
    int i;
    while(up<down && left<right)
    {
        for(i=left;up<down && i<right;++i)
        {
            cout<<matrix[up][i]<<" ";
        }
        up++;
        for(i=up;left<right && i<down;++i)
        {
            cout<<matrix[i][right-1]<<" ";
        }
        right--;
        for(i=right-1;up<down && i>=left;--i)
        {
            cout<<matrix[down-1][i]<<" ";
        }
        down--;
        for(i=down-1;left<right && i>=up;--i)
        {
            cout<<matrix[i][left]<<" ";
        }
        left++;
    }
    cout<<endl;
}


//-------测试代码---------
void test()
{
    int arr1[3][4]={ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    int arr2[5]={1,2,3,4,5};
    int arr3[3][1]={ {1},{2},{3} };
    int arr4[1]={1};

    vector<vector<int> > matrix1;
    vector<vector<int> > matrix2;
    vector<vector<int> > matrix3;
    vector<vector<int> > matrix4;
    vector<int> tmp;
    int i,j;

    for(i=0;i<3;++i)
    {
        tmp.clear();
        for(j=0;j<4;++j)
        {
            tmp.push_back(arr1[i][j]);
        }
        matrix1.push_back(tmp);
    }

    for(i=0;i<1;++i)
    {
        tmp.clear();
        for(j=0;j<5;++j)
        {
            tmp.push_back(arr2[j]);
        }
        matrix2.push_back(tmp);
    }

    for(i=0;i<3;++i)
    {
        tmp.clear();
        for(j=0;j<1;++j)
        {
            tmp.push_back(arr3[i][j]);
        }
        matrix3.push_back(tmp);
    }

    for(i=0;i<1;++i)
    {
        tmp.clear();
        for(j=0;j<1;++j)
        {
            tmp.push_back(arr4[j]);
        }
        matrix4.push_back(tmp);
    }
    PrintMatrixClockwisely(matrix1);
    PrintMatrixClockwisely(matrix2);
    PrintMatrixClockwisely(matrix3);
    PrintMatrixClockwisely(matrix4);
}

int main()
{
    test();
    return 0;
}
