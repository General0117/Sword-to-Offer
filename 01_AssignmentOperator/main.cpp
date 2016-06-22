//
//Author:SmartBrave
//

#include<iostream>
#include<string.h>
using namespace std;

/*   类声明  */
class CMyString{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);

    //CMyString& operator=(const CMyString& str);
    CMyString& operator=(CMyString str);

    void print()const
    {
        if(m_pData!=NULL)
            cout<<m_pData<<endl;
        else
            cout<<"NULL"<<endl;
    }
private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
    :m_pData(pData)
{
    if(pData!=NULL)
    {
        size_t len=strlen(pData);
        m_pData=new char[len+1];
        memcpy(m_pData,pData,len+1);
    }
}
CMyString::CMyString(const CMyString& str)
    :m_pData(str.m_pData)
{
    if(str.m_pData!=NULL)
    {
        size_t len=strlen(str.m_pData);
        m_pData=new char[len+1];
        memcpy(m_pData,str.m_pData,len+1);
    }
}
CMyString::~CMyString(void)
{
    if(m_pData!=NULL)
    {
        delete []m_pData;
        m_pData=NULL;
    }
}

//version 1
//最普通的写法，但没有考虑到自赋值的情况和异常安全性
//CMyString& CMyString::operator=(const CMyString& str)
//{
//    delete []m_pData;
//    m_pData=NULL;
//    size_t len=strlen(str.m_pData);
//    m_pData=new char[len+1];
//    memcpy(m_pData,str.m_pData,len+1);
//    return *this;
//}

//version 2
//比上个版本好一点，检查了自赋值的情况
//但如果new操作符失败而抛出异常，会导致自己原来的空间被释放
//CMyString& CMyString::operator=(const CMyString& str)
//{
//    if(&str!=this)
//    {
//        delete []m_pData;
//        m_pData=NULL;
//        size_t len=strlen(str.m_pData);
//        m_pData=new char[len+1];
//        memcpy(m_pData,str.m_pData,len+1);
//    }
//    return *this;
//}

//version 3
//交换当前指针和一个临时对象，该对象析构时会释放掉当前的指针
//由于swap是原子操作，所以有很好的异常安全性
//CMyString& CMyString::operator=(const CMyString& str)
//{
//    CMyString tmp(str.m_pData);
//    std::swap(tmp.m_pData,m_pData);
//    return *this;
//}

//version 4
//和版本3原理一样,但需要修改函数声明
CMyString& CMyString::operator=(CMyString str)
{
    swap(str.m_pData,m_pData);
    return *this;
}



//----------测试代码------------

void test1()
{
    CMyString s1(NULL);                 //用空指针初始化
    CMyString s2("Hello Smart!");       //正常初始化
    CMyString s3(s2);                   //拷贝构造
    CMyString s4;
    s4=s3;                              //赋值
    CMyString s5("You are a good boy!");
    s5=s5;                              //自赋值
    CMyString s6(s1);
    CMyString s7(s1);
    s6=s7=s5;                           //连续赋值
    
    s1.print();
    s2.print();
    s3.print();
    s4.print();
    s5.print();
    s6.print();
    s7.print();

}

int main()
{
    test1();
    return 0;
}
