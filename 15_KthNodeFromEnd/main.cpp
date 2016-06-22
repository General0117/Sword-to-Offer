#include<iostream>
#include<stack>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int data=int()):value(data),next(NULL)
    {}
};

class ListIsTooShort{};

//递归法
//ListNode* _FindKthToTail(ListNode* head,int& k)
//{
//    if(head==NULL)
//    {
//        return  NULL;
//    }
//    else
//    {
//        ListNode* tmp=_FindKthToTail(head->next,k);
//        if(k==0)
//            return tmp;
//    }
//    if(k==1)
//    {
//        k=0;
//        return head;
//    }
//    else if(k>1)
//        k--;
//}
//
//ListNode* FindKthToTail(ListNode* head,int k)throw(ListIsTooShort)
//{
//    ListNode* tmp=_FindKthToTail(head,k);
//    if(k==0)
//        return tmp;
//    else
//        throw ListIsTooShort();
//}

//自定义栈法
ListNode* FindKthToTail(ListNode* head,int k)throw(ListIsTooShort)
{
    if(head==NULL || k<=0)
        return NULL;
    stack<ListNode*> s;
    while(head!=NULL)
    {
        s.push(head);
        head=head->next;
    }
    while(--k!=0 && !s.empty())
    {
        s.pop();
    }
    if(k==0)
        return s.top();
    else
        throw ListIsTooShort();
}


//前后指针法
//ListNode* FindKthToTail(ListNode* head,int k)throw(ListIsTooShort)
//{
//    if(head==NULL || k==0)
//        return NULL;
//    ListNode* front=head,*last=head;
//    while(k-->0 && front!=NULL)
//    {
//        front=front->next;
//    }
//    if(k>0)
//    {
//        throw ListIsTooShort();
//    }
//    else
//    {
//        while(front!=NULL)
//        {
//            front=front->next;
//            last=last->next;
//        }
//    }
//    return last;
//}

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
    try{
        cout<<"the 1st Node to End is:"<<FindKthToTail(list,1)->value<<endl;
    }
    catch(const ListIsTooShort&)
    {
        cout<<"this list is too short!"<<endl;
    }
    try{
        cout<<"the 2st Node to End is:"<<FindKthToTail(list,2)->value<<endl;
    }
    catch(const ListIsTooShort&)
    {
        cout<<"this list is too short!"<<endl;
    }
    try{
        cout<<"the 11st Node to End is:"<<FindKthToTail(list,11)->value<<endl;
    }
    catch(const ListIsTooShort&)
    {
        cout<<"this list is too short!"<<endl;
    }
    try{
        cout<<"the 15st Node to End is:"<<FindKthToTail(list,15)->value<<endl;
    }
    catch(const ListIsTooShort&)
    {
        cout<<"this list is too short!"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
