#include<iostream>
using namespace std;

//version 01:have some bug to fix
//bool MatchCore(char* str,int poss,char* pattern,int posp)//poss:the postion of str,posp:the postion of pattern 
//{
//    if(*str=='\0' && *pattern=='\0')
//        return true;
//    if(*str!='\0' && *pattern=='\0')
//        //return true;
//        return false;
//    //if(*str=='\0' && *pattern!='\0')
//    //    return false;
//    if(*pattern=='.')
//    {
//        if(*(pattern+1)!='*')
//            return MatchCore(str+1,poss+1,pattern+1,posp+1);
//        else
//            return MatchCore(str,poss,pattern+1,posp+1);
//    }
//    if(*pattern!='*')
//    {
//        if(*(pattern+1)!='*')
//        {
//            if(*pattern==*str)
//                return MatchCore(str+1,poss+1,pattern+1,posp+1);
//            else
//                return false;
//        }
//        else//next char is '*'
//        {
//            if(*pattern==*str)
//                return MatchCore(str,poss,pattern+1,posp+1);
//            else
//                return MatchCore(str,poss,pattern+2,posp+2);
//        }
//    }
//    else//*pattern=='*'
//    {
//        if(posp==0)
//        {
//            return false;//pattern is error
//        }
//        else
//        {
//            //if((poss>0 && *str==*(str-1)) || *str==*(str+1))
//            if(*str==*(pattern-1))
//                return MatchCore(str,poss,pattern+1,posp+1) || MatchCore(str+1,poss+1,pattern+1,posp+1) || MatchCore(str+1,poss+1,pattern,posp);
//            else
//                return MatchCore(str,poss,pattern+1,posp+1) || MatchCore(str+1,poss+1,pattern+1,posp+1);
//        }
//    }
//}

bool MatchCore(char* str,char* pattern)
{
    if(*str=='\0' && *pattern=='\0')
        return true;
    if(*str!='\0' && *pattern=='\0')
        return false;
    if(*(pattern+1)=='*')
    {
        if(*pattern==*str || (*pattern=='.' && *str!='\0'))
            return MatchCore(str+1,pattern+2) 
                || MatchCore(str+1,pattern)
                || MatchCore(str,pattern+2);
        else
            return MatchCore(str,pattern+2);
    }
    if(*str==*pattern || (*pattern=='.' && *str!='\0'))
        return MatchCore(str+1,pattern+1);
    return false;
}

bool match(char* str,char* pattern)
{
    if(str==NULL || pattern==NULL)
        return false;
    return MatchCore(str,pattern);
}

//------测试代码------
void testmatch(int& count,char* str,char* pattern,bool expected)
{
    if(str==NULL || pattern==NULL)
        return ;
    cout<<"str: "<<str<<"  pattern: "<<pattern<<"  expected: "<<expected<<"  result: ";
    bool res=match(str,pattern);
    if(expected!=res)
        count++;
    cout<<res<<endl;
}
void test()
{
    int count=0;
    testmatch(count,"", "", true);
    testmatch(count,"", ".*", true);
    testmatch(count,"", ".", false);
    testmatch(count,"", "c*", true);
    testmatch(count,"a", ".*", true);
    testmatch(count,"a", "a.", false);
    testmatch(count,"a", "", false);
    testmatch(count,"a", ".", true);
    testmatch(count,"a", "ab*", true);
    testmatch(count,"a", "ab*a", false);
    testmatch(count,"aa", "aa", true);
    testmatch(count,"aa", "a*", true);
    testmatch(count,"aa", ".*", true);
    testmatch(count,"aa", ".", false);
    testmatch(count,"ab", ".*", true);
    testmatch(count,"ab", ".*", true);
    testmatch(count,"aaa", "aa*", true);
    testmatch(count,"aaa", "aa.a", false);
    testmatch(count,"aaa", "a.a", true);
    testmatch(count,"aaa", ".a", false);
    testmatch(count,"aaa", "a*a", true);
    testmatch(count,"aaa", "ab*a", false);
    testmatch(count,"aaa", "ab*ac*a", true);
    testmatch(count,"aaa", "ab*a*c*a", true);
    testmatch(count,"aaa", ".*", true);
    testmatch(count,"aab", "c*a*b", true);
    testmatch(count,"aaca", "ab*a*c*a", true);
    testmatch(count,"aaba", "ab*a*c*a", false);
    testmatch(count,"bbbba", ".*a*a", true);
    testmatch(count,"bcbbabab", ".*a*a", false);
    cout<<count<<endl;
}

int main()
{
    test();
    return 0;
}
