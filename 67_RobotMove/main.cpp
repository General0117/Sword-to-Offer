#include<iostream>
#include<boost/shared_array.hpp>
using namespace std;
using namespace boost;

bool IsGreater(int num1,int num2,int k)
{
    int sum=0;
    while(num1)
    {
        sum+=num1%10;
        num1/=10;
    }
    while(num2)
    {
        sum+=num2%10;
        num2/=10;
    }
    return sum>k;
}

void MovingCountCore(int rows,int cols,int row,int col,/*bool**/shared_array<bool> visited,int& count,int k)
{
    if(rows<=0 || cols<=0 || row>=rows || col>=cols ||row<0 || col<0 || visited==NULL)
        return ;
    if(visited[row*cols+col]==false)
    {
        if(IsGreater(row,col,k))
            return ;
        count++;
        visited[row*cols+col]=true;
    }
    else
        return ;
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
        MovingCountCore(rows,cols,y,x,visited,count,k);
    }
    //visited[row*cols+col]=false;
    return ;
}

int MovingCount(int rows,int cols,int k)
{
    if(rows<=0 || cols<=0 || k<0)
        throw std::exception();
    //bool* visited=new bool[rows*cols];
    shared_array<bool> visited(new bool[rows*cols]);
    //memset(visited,false,sizeof(visited));
    for(int i=0;i<rows*cols;++i)
    {
        visited[i]=false;
    }
    int count=0;
    MovingCountCore(rows,cols,0,0,visited,count,k);
    //delete []visited;
    return count;
}

//-----测试代码-----
void test()
{
    int m[8]={10,20,1,1,100,10,1,10};
    int n[8]={10,20,100,10,1,1,1,10};
    int k[8]={5,15,10,10,15,15,15,-10};
    int expected[8]={21,359,29,10,79,10,1,0};
    int i;
    int res;
    for(i=0;i<8;++i)
    {
        try
        {
            res=MovingCount(m[i],n[i],k[i]);
        }
        catch(...)
        {
            cout<<"throw some expection!"<<endl;
            continue;
        }
        cout<<res<<" ";
        if(res==expected[i])
            cout<<"pass!"<<endl;
        else
            cout<<"fail!"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
