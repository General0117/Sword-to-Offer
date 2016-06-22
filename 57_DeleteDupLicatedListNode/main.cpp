#include<iostream>
#include<unistd.h>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int data=int()):value(data),next(NULL)
    {}
};

void deleteDuplication(ListNode** plist)
{
    if(plist==NULL || *plist==NULL)
        return;
    ListNode* list=(*plist)->next;
    ListNode* tmp=NULL;
    while(list!=NULL && list->next!=NULL)
    {
        if(list->value==(*plist)->value)
        {
            tmp=list->next;
            while(tmp!=NULL && tmp->value==list->value)
            {
                list->next=tmp->next;
                delete tmp;
                tmp=list->next;
            }
            delete list;
            delete *plist;
            *plist=tmp;
            list=*plist==NULL?NULL:(*plist)->next;
        }
        else
        {
            deleteDuplication(&((*plist)->next));
            if((*plist)->next==NULL)
            {
                list=NULL;
            }
            else
            {
                list=(*plist)->next->next;
            }
            //tmp=list->next;
            //bool flag=false;
            //while(tmp!=NULL && tmp->value==list->value)
            //{
            //    flag=true;
            //    list->next=tmp->next;
            //    delete tmp;
            //    tmp=list->next;
            //}
            //if(flag)
            //{
            //    tmp=list->next;
            //    delete list;
            //    list=tmp;
            //}
            //list=list->next;
        }
    }
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
    int arr[]={1,2,3,3,4,4,5};
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
            tail=tail->next;
        }
    }
    printList(list);
    deleteDuplication(&list);
    printList(list);
}

int main()
{
    test();
    return 0;
}
