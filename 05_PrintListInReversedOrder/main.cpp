//
//Author:SmartBrave
//

#include<iostream>
#include<stack>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
    node(int x):data(x),next(NULL)
    {}
}list;

//version 1
//如果允许改变原来的链表，就可以将原来链表逆转，然后打印输出
//list* PrintListInReversedOrder(list* &head)
//{
//    if(head==NULL || head->next==NULL)
//        return head;
//    list* tmp=NULL;
//    list* cur=head->next;
//    head->next=NULL;
//    while(cur!=NULL)
//    {
//        tmp=cur->next;
//        cur->next=head;
//        head=cur;
//        cur=tmp;
//    }
//    cur=head;
//    while(cur!=NULL)
//    {
//        cout<<cur->data<<" ";
//        cur=cur->next;
//    }
//    cout<<endl;
//    return head;
//}

//version 2
//如果不允许改变原来的链表，就可以采用递归方式
//void PrintListInReversedOrder(list* head)
//{
//    if(head==NULL)
//        return;
//    PrintListInReversedOrder(head->next);
//    cout<<head->data<<" ";
//}

//version 3
//如果链表太长，多次递归可能会导致栈溢出，所以我们可以用自定义的栈代替系统栈
void PrintListInReversedOrder(list* head)
{
    stack<list*> s;
    list* cur=head;
    while(cur!=NULL)
    {
        s.push(cur);
        cur=cur->next;
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

//---------测试代码----------
void test()
{
    list* head=new list(1);
    list* tail=head;
    int i;
    for(i=2;i<11;++i)
    {
        tail->next=new list(i);
        tail=tail->next;
    }
    list* cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
    PrintListInReversedOrder(head);
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
