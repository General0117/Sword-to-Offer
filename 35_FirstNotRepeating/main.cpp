#include<iostream>
#include<string>
#include<vector>
using namespace std;

char FirstNotRepeatingChar(const string& str)
{
    vector<int> count;
    count.resize(256);
    int i;
    for(i=0;i<256;++i)
    {
        count[i]=0;
    }
    for(i=0;i<str.size();++i)
    {
        count[str[i]]++;
    }
    for(i=0;i<str.size();++i)
    {
        if(count[str[i]]==1)
            return str[i];
    }
    throw new exception();
}

//---------测试代码--------
void test()
{
    //string str="abaccdeff";
    //string str="aabbccddeeff";
    string str="abcdefg";
    try
    {
        cout<<FirstNotRepeatingChar(str)<<endl;
    }
    catch(exception*)
    {
        cout<<"error!"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
