#include<iostream>
using namespace std;

struct ComplexListNode{
    int         value;
    ComplexListNode*   next;
    ComplexListNode*   sibling;
    ComplexListNode(int data=int()):value(data),next(NULL),sibling(NULL)
    {}
    ComplexListNode(const ComplexListNode& s)
        :next(NULL),sibling(NULL)
    {
        value=s.value;
    }
};

ComplexListNode* Clone(ComplexListNode* head)
{
    if(head==NULL)
        return NULL;
    ComplexListNode* cur=head;
    ComplexListNode* tmp=head;
    ComplexListNode* newhead=NULL;;
    ComplexListNode* newtail=NULL;
    while(cur!=NULL)
    {
        tmp=cur->next;
        cur->next=new ComplexListNode(cur->value);
        cur=cur->next;
        cur->next=tmp;
        cur=cur->next;
    }
    cur=head;
    while(cur!=NULL)
    {
        tmp=cur->next;
        if(cur->sibling!=NULL)
            tmp->sibling=cur->sibling->next;
        cur=cur->next;
        cur=cur->next;
    }
    cur=head;
    newhead=newtail=cur->next;
    while(cur!=NULL)
    {
        cur->next=newtail->next;
        cur=cur->next;
        if(cur!=NULL)
        {
            newtail->next=cur->next;
            newtail=newtail->next;
        }
    }
    return newhead;
}



//-------测试代码-----
void printList(ComplexListNode* list)
{
    if(list==NULL)
    {
        cout<<"Nothing!"<<endl;
        return;
    }
    while(list!=NULL)
    {
        cout<<list->value<<"(sib:";
        if(list->sibling==NULL)
            cout<<"NULL";
        else
            cout<<list->sibling->value;
        cout<<") ";
        list=list->next;
    }
    cout<<endl;
}
void test()
{
    int arr[]={0,1,2,3,4};
    int sib[]={2,4,-1,1,4};
    int i,j;
    ComplexListNode* list=NULL;
    ComplexListNode* tail=NULL;
    ComplexListNode* cur=NULL;
    ComplexListNode* tmp=NULL;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        if(list==NULL)
        {
            list=new ComplexListNode(arr[i]);
            tail=list;
        }
        else
        {
            tail->next=new ComplexListNode(arr[i]);
            tail=tail->next;
        }
    }
    cur=list;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        if(cur==NULL)
            break;
        if(sib[i]==-1)
            tmp=NULL;
        else
            tmp=list;
        for(j=0;j<sib[i];++j)
        {
            tmp=tmp->next;
        }
        cur->sibling=tmp;
        cur=cur->next;
    }
    printList(list);
    printList(Clone(list));
}

int main()
{
    test();
    return 0;
}
