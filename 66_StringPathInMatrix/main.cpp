#include<iostream>
#include<boost/shared_array.hpp>
using namespace std;
using namespace boost;

bool HasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int pathLength,/*bool**/shared_array<bool> visited)
{
    if(matrix==NULL || rows<=0 || cols<=0 || row>=rows || col>=cols ||row<0 || col<0 || str==NULL || pathLength<0 || visited==NULL)
        return false;
    if(str[pathLength]=='\0')
        return true;
    if(visited[row*cols+col]==false)
    {
        if(matrix[row*cols+col]!=str[pathLength])
            return false;
        visited[row*cols+col]=true;
        pathLength++;
    }
    else
        return false;
    int x,y;
    for(int i=0;i<4;++i)
    {
        switch(i)
        {
            case 0:
                x=col;
                y=row-1;
                break;
            case 1:
                x=col+1;
                y=row;
                break;
            case 2:
                x=col;
                y=row+1;
                break;
            case 3:
                x=col-1;
                y=row;
                break;
            default:
                break;
        }
        if(HasPathCore(matrix,rows,cols,y,x,str,pathLength,visited)==true)
        {
            return true;
        }
    }
    visited[row*cols+col]=false;
    return false;
}

bool HasPath(char* matrix,int rows,int cols,char* str)
{
    if(matrix==NULL || rows<=0 || cols<=0 || str==NULL)
        return false;
    //bool* visited=new bool[rows*cols];
    shared_array<bool> visited(new bool[rows*cols]);
    //memset(visited,false,sizeof(visited));
    for(int i=0;i<rows*cols;++i)
    {
        visited[i]==false;
    }
    int row,col;
    int pathLength=0;
    for(row=0;row<rows;++row)
    {
        for(col=0;col<cols;++col)
        {
            if(HasPathCore(matrix,rows,cols,row,col,str,pathLength,visited)==true)
            {
                //delete []visited;
                return true;
            }
        }
    }
    //delete []visited;
    return false;
}


//-----测试代码-----
void test()
{
    char* matrix="abcesfcsadee";
    int rows=3,cols=4;
    char* str="bcced";
    //char* str="abcb";
    if(HasPath(matrix,rows,cols,str))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}

int main()
{
    test();
    return 0;
}
