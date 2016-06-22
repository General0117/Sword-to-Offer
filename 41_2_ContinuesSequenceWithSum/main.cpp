#include<iostream>
#include<vector>
using namespace std;

void print(int left,int right)
{
    int i;
    for(i=left;i<=right;++i)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

bool FindContinuousSequence(int sum)
{
    if(sum<3)
        return false;
    int middle=(sum+1)/2;
    int left=1,right=2;
    int cursum=left+right;
    while(left<=middle)
    {
        if(cursum==sum)
        {
            print(left,right);
            cursum-=left;
            left++;
        }
        else if(cursum<sum)
        {
            right++;
            cursum+=right;
        }
        else
        {
            cursum-=left;
            left++;
        }
    }
}

//------测试代码------
void test()
{
    int sum=15;
    FindContinuousSequence(sum);
}

int main()
{
    test();
    return 0;
}
