#include<iostream>
using namespace std;

struct ListNode{
    int         value;
    ListNode*   next;
    ListNode(int data=int()):value(data),next(NULL)
    {}
};

//version 1
//常规做法，依次遍历
//时间复杂度为O(n)
//void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
//{
//    if(pListHead==NULL || *pListHead==NULL || pToBeDeleted==NULL)
//        return;
//    ListNode* cur=*pListHead;
//    if(cur==pToBeDeleted)
//    {
//        *pListHead=cur->next;
//        delete cur;
//        return;
//    }
//    while(cur->next!=NULL)
//    {
//        if(cur->next==pToBeDeleted)
//        {
//            ListNode* tmp=cur->next;
//            cur->next=tmp->next;
//            delete tmp;
//            return;
//        }
//        cur=cur->next;
//    }
//}

//version 2
//时间复杂度为O(1)
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
    if(pListHead==NULL || *pListHead==NULL || pToBeDeleted==NULL)
        return;
    if(pToBeDeleted->next!=NULL)
    {
        ListNode* tmp=pToBeDeleted->next;
        pToBeDeleted->value=tmp->value;
        pToBeDeleted->next=tmp->next;
        delete tmp;
    }
    else
    {
        ListNode* cur=*pListHead;
        if(cur==pToBeDeleted)
        {
            *pListHead=cur->next;
            delete cur;
            return;
        }
        while(cur->next!=NULL)
        {
            if(cur->next==pToBeDeleted)
            {
                ListNode* tmp=cur->next;
                cur->next=tmp->next;
                delete tmp;
                return;
            }
            cur=cur->next;
        }
    }
}

//---------测试代码---------
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

ListNode* find(ListNode* list,int x)
{
    if(list==NULL)
        return NULL;
    while(list!=NULL)
    {
        if(list->value==x)
            return list;
        list=list->next;
    }
    return NULL;
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
    DeleteNode(&list,find(list,0));//删除链表第一个节点
    printList(list);
    DeleteNode(&list,find(list,5));//删除链表中间的节点
    printList(list);
    DeleteNode(&list,find(list,10));//删除链表最后一个节点
    printList(list);

    ListNode* list2=new ListNode(11);//链表中只有一个节点
    printList(list2);
    DeleteNode(&list2,find(list2,11));
    printList(list2);
}

int main()
{
    test();
    return 0;
}
