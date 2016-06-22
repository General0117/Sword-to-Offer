#include<iostream>
#include<string>
using namespace std;

char FindFirstCharInString(const string& str)
{
    static int arr[256];
    int i=0;
    for(i=0;i<str.size();++i)
    {
        arr[str[i]]++;
    }
    for(i=0;i<str.size();++i)
    {
        if(arr[str[i]]==1)
            return str[i];
    }
    throw exception();
}

//----测试代码----
void test()
{
    string str="google";
    cout<<FindFirstCharInString(str)<<endl;
}

int main()
{
    test();
    return 0;
}
