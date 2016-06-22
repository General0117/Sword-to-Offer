#include<iostream>
#include<limits.h>
#include<string>
using namespace std;


int IsError=0;
int StrToInt(const string& str)
{
    bool greater0=true;
    int start=0;
    unsigned int res=0;
    int length=str.size();
    int i=0;
    while(start<length && (str[start]==' ' || str[start]==0x9) && ++start);
    if(start<length && str[start]=='-')
    {
        greater0=false;
        start++;
    }
    else if(start<length && str[start]=='+')
    {
        greater0=true;
        start++;
    }
    i=start;
    while(i<length)
    {
        if(isdigit(str[i]))
        {
            if(INT_MAX/10 >= res)
                res=res*10;
            else
                return greater0?INT_MAX:INT_MIN;
            if(INT_MAX-(str[i]-'0')>=res)
                res+=(str[i]-'0');
            else
                return greater0?INT_MAX:INT_MIN;
        }
        else
        {
            break;
        }
        i++;
    }
    if(length==0 || (res==0 && i<length))
    {
        IsError=1;
        return 0;
    }
    return (int)(greater0?res:-res);
}

//------测试代码------
void test()
{
    //string str="1234567890";
    //string str="9876543210";
    //string str="-32";
    //string str="     32";
    //string str="   +32fdslk";
    //string str="";
    //string str="-";
    string str="-fsd;klajf";
    cout<<StrToInt(str)<<endl;
}

int main()
{
    test();
    return 0;
}
