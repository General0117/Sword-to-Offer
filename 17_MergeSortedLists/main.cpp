#include<iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int data=int()):value(data),next(NULL)
    {}
};

ListNode* Merge(ListNode* head1,ListNode* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    ListNode* newhead=NULL;
    ListNode* tail=NULL;
    ListNode* tmp=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->value > head2->value)
        {
            tmp=head2;
            head2=head2->next;
        }
        else
        {
            tmp=head1;
            head1=head1->next;
        }
        if(newhead==NULL)
        {
            newhead=tmp;
            tail=tmp;
        }
        else
        {
            tail->next=tmp;
            tail=tail->next;
        }
    }
    while(head1!=NULL)
    {
        if(newhead==NULL)
        {
            newhead=head1;
            tail=head1;
        }
        else
        {
            tail->next=head1;
            tail=tail->next;
        }
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        if(newhead==NULL)
        {
            newhead=head2;
            tail=head2;
        }
        else
        {
            tail->next=head2;
            tail=tail->next;
        }
        head2=head2->next;
    }
    tail->next=NULL;
    return newhead;
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
    int arr1[]={0,2,4,6,8,10};
    int arr2[]={1,3,5,7,9};
    int i;
    ListNode* list1=NULL,*list2=NULL;
    ListNode* tail1=NULL,*tail2=NULL;
    for(i=0;i<sizeof(arr1)/sizeof(arr1[0]);++i)
    {
        if(list1==NULL)
        {
            list1=new ListNode(arr1[i]);
            tail1=list1;
        }
        else
        {
            tail1->next=new ListNode(arr1[i]);
            tail1=tail1->next;
        }
    }
    for(i=0;i<sizeof(arr2)/sizeof(arr2[0]);++i)
    {
        if(list2==NULL)
        {
            list2=new ListNode(arr2[i]);
            tail2=list2;
        }
        else
        {
            tail2->next=new ListNode(arr2[i]);
            tail2=tail2->next;
        }
    }
    printList(list1);
    printList(list2);
    printList(Merge(list1,list2));
}

int main()
{
    test();
    return 0;
}
