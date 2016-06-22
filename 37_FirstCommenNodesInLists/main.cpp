#include<iostream>
#include<stack>
using namespace std;

struct ListNode{
    int         value;
    ListNode*   next;
    ListNode(int data=int()):value(data),next(NULL)
    {}
};

//ListNode* FindFirstCommenNode(ListNode* head1,ListNode* head2)
//{
//    if(head1==NULL || head2==NULL)
//        return NULL;
//    ListNode* cur1=head1,*cur2=head2;
//    while(cur1!=NULL)
//    {
//        cur2=head2;
//        while(cur2!=NULL)
//        {
//            if(cur1==cur2)
//                return cur1;
//            cur2=cur2->next;
//        }
//        cur1=cur1->next;
//    }
//    return NULL;
//}

//ListNode* FindFirstCommenNode(ListNode* head1,ListNode* head2)
//{
//    if(head1==NULL || head2==NULL)
//        return NULL;
//    stack<ListNode*> s1,s2;
//    ListNode* cur1=head1,*cur2=head2;
//    while(cur1!=NULL || cur2!=NULL)
//    {
//        if(cur1!=NULL)
//        {
//            s1.push(cur1);
//            cur1=cur1->next;
//        }
//        if(cur2!=NULL)
//        {
//            s2.push(cur2);
//            cur2=cur2->next;
//        }
//    }
//    while(!s1.empty() || !s2.empty())
//    {
//        if(!s1.empty() && !s2.empty())
//        {
//            if(s1.top()==s2.top())
//            {
//                s1.pop();
//                s2.pop();
//            }
//            else
//            {
//                return s1.top()->next;
//            }
//        }
//        else if(!s1.empty())
//        {
//            if(s1.top()->next==head2)
//            {
//                return head2;
//            }
//            else
//            {
//                return NULL;
//            }
//        }
//        else if(!s2.empty())
//        {
//            if(s2.top()->next==head1)
//            {
//                return head1;
//            }
//            else
//            {
//                return NULL;
//            }
//        }
//    }
//    if(s1.empty() && s2.empty())
//        return head1;
//}

ListNode* FindFirstCommenNode(ListNode* head1,ListNode* head2)
{
    if(head1==NULL || head2==NULL)
        return NULL;
    int count1=0,count2=0;
    int i;
    ListNode* cur1=head1,*cur2=head2;
    while(cur1!=NULL)
    {
        count1++;
        cur1=cur1->next;
    }
    while(cur2!=NULL)
    {
        count2++;
        cur2=cur2->next;
    }
    cur1=head1,cur2=head2;
    if(count1>count2)
    {
        for(i=0;i<count1-count2;++i)
        {
            cur1=cur1->next;
        }
    }
    else if(count2>count1)
    {
        for(i=0;i<count2-count1;++i)
        {
            cur2=cur2->next;
        }
    }
    while(cur1!=NULL && cur2!=NULL)
    {
        if(cur1==cur2)
        {
            return cur1;
        }
        else
        {
            cur1=cur1->next;
            cur2=cur2->next;
        }
    }
}

////--------测试代码--------
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
    ListNode* list1=list;
    ListNode* list2=list->next->next;
    ListNode* list3=tail;
    ListNode* list4=new ListNode(5);
    ListNode* list5=new ListNode(5);
    list5->next=list2;
    ListNode* tmp=NULL;
    cout<<((tmp=FindFirstCommenNode(list,list1))==NULL?-1:tmp->value)<<endl;
    cout<<((tmp=FindFirstCommenNode(list,list2))==NULL?-1:tmp->value)<<endl;
    cout<<((tmp=FindFirstCommenNode(list,list3))==NULL?-1:tmp->value)<<endl;
    cout<<((tmp=FindFirstCommenNode(list,list4))==NULL?-1:tmp->value)<<endl;
    cout<<((tmp=FindFirstCommenNode(list,list5))==NULL?-1:tmp->value)<<endl;
}

int main()
{
    test();
    return 0;
}
