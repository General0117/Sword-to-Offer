#include<iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int data=int()):value(data),next(NULL)
    {}
};

//ListNode* ReverseList(ListNode* head)
//{
//    if(head==NULL)
//        return NULL;
//    ListNode* cur=head->next;
//    head->next=NULL;
//    ListNode* next=NULL;
//    while(cur!=NULL)
//    {
//        next=cur->next;
//        cur->next=head;
//        head=cur;
//        cur=next;
//    }
//    return head;
//}

ListNode* _ReverseList(ListNode* head,ListNode*& tail)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        tail=head;
        return head;
    }
    ListNode* tmp=_ReverseList(head->next,tail);
    tail->next=head;
    tail=tail->next;
    return tmp;
}

ListNode* ReverseList(ListNode* head)
{
    if(head==NULL)
        return NULL;
    ListNode* tail=NULL;
    ListNode* tmp=_ReverseList(head,tail);
    tail->next=NULL;
    return tmp;
}

//------测试代码-------
void printList(ListNode* list)
{
    if(list==NULL)
    {
        cout<<"Nothing!"<<endl;
        return;
    }
    while(list!=NULL)
    {
        cout<<list->value<<" ";
        list=list->next;
    }
    cout<<endl;
}

void test()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9,10};
    int i;
    ListNode* list=NULL;
    ListNode* tail=NULL;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        if(list==NULL)
        {
            list=new ListNode(arr[i]);
            tail=list;
        }
        else
        {
            tail->next=new ListNode(arr[i]);
            tail=tail->next;
        }
    }
    printList(list);
    list=ReverseList(list);
    printList(list);
}

int main()
{
    test();
    return 0;
}
