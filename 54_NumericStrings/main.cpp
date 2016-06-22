#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

bool scanDigits(char** string)
{
    bool flag=false;
    while(**string!='\0' && **string>='0' && **string<='9')
    {
        ++(*string);
        flag=true;
    }
    return flag;
}

bool isExponential(char** string)
{
    ++(*string);
    if(**string=='+' || **string=='-')
        ++(*string);
    if(**string=='\0')
        return false;
    if(scanDigits(string)==false)
        return false;
    return **string == '\0';
}

bool isNumeric(char* string)
{
    //if(strcmp(itoa(atoi(str.c_str())),str)==0)
    //    return true;
    //else
    //    return false;
    if(string==NULL)
        return false;
    if(*string=='+' || *string=='-')
        ++string;
    if(*string=='\0')
        return false;
    bool numeric=true;

    if(scanDigits(&string)==false)
        return false;
    if(*string!='\0')
    {
        if(*string=='.')
        {
            ++string;
            if(scanDigits(&string)==false)
                return false;
            if(*string=='e' || *string=='E')
                numeric=isExponential(&string);
        }
        else if(*string=='e' || *string=='E')
            numeric=isExponential(&string);
        else
            numeric=false;
    }
    return numeric && *string=='\0';
}

//------测试代码------
void test(char* str,bool expected)
{
    cout<<"str: "<<str<<"  expected: "<<expected<<"  res: "<<isNumeric(str)<<endl;
}

int main()
{
    test("100", true);
    test("123.45e+6", true);
    test("+500", true);
    test("5e2", true);
    test("3.1416", true);
    test("600.", false);
    test("-.123", false);
    test("-1E-16", true);
    test("1.79769313486232E+308", true);

    test( "12e", false);
    test( "1a3.14", false);
    test( "1+23", false);
    test( "1.2.3", false);
    test( "+-5", false);
    test( "12e+5.4", false);
    test( ".", false);
    test( ".e1", false);
    test( "+.", false);
    return 0;
}
