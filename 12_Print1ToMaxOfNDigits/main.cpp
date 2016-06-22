#include<iostream>
#include<string>
using namespace std;

void PrintNumber(const string& number)
{
    int i;
    int length=number.size();
    for(i=0;i<length;++i)
    {
        if(number[i]!='0')
            break;
    }
    for(;i<length;++i)
    {
        cout<<number[i];
    }
    cout<<endl;
}

bool Increment(string& number)
{
    int length=number.size();
    bool IsOverFlow=false;
    int nTakeOver=0;
    int i;
    for(i=length-1;i>=0;--i)
    {
        number[i]+=nTakeOver;
        if(i==length-1)
            number[i]++;
        if(number[i]>=(10+'0'))
        {
            if(i==0)
                return true;
            else
            {
                number[i]-=10;
                nTakeOver=1;
            }
        }
        else
        {
            return false;
        }
    }
    return false;
}

void Print1ToMaxOfNDigits(int n)
{
    string number;
    number.resize(n);
    int i;
    for(i=0;i<n;++i)
    {
        number[i]='0';
    }
    while(!Increment(number))
    {
        PrintNumber(number);
    }
}


//------测试代码-------
void test()
{
    int n=10;
    Print1ToMaxOfNDigits(n);
}

int main()
{
    test();
    return 0;
}
