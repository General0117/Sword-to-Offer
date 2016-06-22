#include<iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int data=int()):value(data),next(NULL)
    {}
};

ListNode* MeetingNode(ListNode* head)
{
    if(head==NULL)
        return NULL;
    ListNode* fast=head->next,*slow=head;
    while(fast!=NULL && fast!=slow)
    {
        fast=fast->next;
        if(fast==NULL)
            return fast;
        if(fast==slow)
            return fast;
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}

ListNode* EntryNodeOfLoop(ListNode* head)
{
    if(head==NULL)
        return NULL;
    ListNode* tmp=MeetingNode(head);
    int count=1;
    ListNode* cur=tmp->next;
    while(cur!=NULL && cur!=tmp)
    {
        count++;
        cur=cur->next;
    }
    tmp=head;
    for(int i=0;i<count;++i)
    {
        tmp=tmp->next;
    }
    cur=head;
    while(cur!=tmp)
    {
        cur=cur->next;
        tmp=tmp->next;
    }
    return cur;
}

//------测试代码------
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
    int arr[]={1,2,3,4,5,6};
    int i;
    ListNode* list=NULL;
    ListNode* tail=NULL;
    ListNode* tmp=NULL;
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
            if(arr[i]==3)
                tmp=tail->next;
            tail=tail->next;
        }
    }
    tail->next=tmp;
    ListNode* res=EntryNodeOfLoop(list);
    if(res==NULL)
        cout<<"NULL"<<endl;
    else
        cout<<res->value<<endl;
}

int main()
{
    test();
    return 0;
}
