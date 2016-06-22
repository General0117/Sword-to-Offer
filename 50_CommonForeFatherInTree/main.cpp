#include<iostream>
#include<list>
#include<stdlib.h>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),parent(NULL),left(NULL),right(NULL)
    {}
};

//if BST
BinaryTreeNode* GetLastCommonNode_BST(BinaryTreeNode* root,BinaryTreeNode* node1,BinaryTreeNode* node2)
{
    if(root==NULL || node1==NULL || node2==NULL)
        return NULL;
    if(node1->value>node2->value)
        swap(node1,node2);
    while(root!=NULL)
    {
        if(root->value == node1->value || root->value == node2->value)
            return root;
        else if(root->value > node1->value && root->value < node2->value)
            return root;
        else if(root->value < node1->value)
            root=root->right;
        else //(root->value > node2->value)
            root=root->left;
    }
    return NULL;
}

BinaryTreeNode* GetFirstCommonNodeInList(BinaryTreeNode* node1,BinaryTreeNode* node2)
{
    if(node1==NULL || node2==NULL)
        return NULL;
    int count1=0,count2=0;
    BinaryTreeNode* cur=node1;
    while(cur!=NULL)
    {
        count1++;
        cur=cur->parent;
    }
    cur=node2;
    while(cur!=NULL)
    {
        count2++;
        cur=cur->parent;
    }
    BinaryTreeNode* LongList=count1>count2?node1:node2;
    BinaryTreeNode* ShortList=count1>count2?node2:node1;
    int sub=abs(count1-count2);
    while(sub--)
    {
        LongList=LongList->parent;
    }
    while(LongList!=NULL && ShortList!=NULL)
    {
        if(LongList==ShortList)
            return LongList;
        else
        {
            LongList=LongList->parent;
            ShortList=ShortList->parent;
        }
    }
    return NULL;
}

//if HasParent pointer
BinaryTreeNode* GetLastCommonNode_HasParent(BinaryTreeNode* root,BinaryTreeNode* node1,BinaryTreeNode* node2)
{
    if(root==NULL || node1==NULL || node2==NULL)
        return NULL;
    return GetFirstCommonNodeInList(node1,node2);
}

void GetPath(BinaryTreeNode* root,BinaryTreeNode* node,list<BinaryTreeNode*>& mylist)
{
    if(root==NULL || node==NULL)
        return;
    mylist.push_back(root);
    if(root->value==node->value)
        return;
    GetPath(root->left,node,mylist);
    if(mylist.back()==node)
        return;
    GetPath(root->right,node,mylist);
    if(mylist.back()==node)
        return;
    mylist.pop_back();
    return;
}

BinaryTreeNode* GetFirstCommonNodeInList(list<BinaryTreeNode*> l1,list<BinaryTreeNode*> l2)
{
    list<BinaryTreeNode*>::iterator it1=l1.begin(),it2=l2.begin();
    while(it1!=l1.end() && it2!=l2.end())
    {
        if(*it1!=*it2)
        {
            it1--;
            return *it1;
        }
        it1++;
        it2++;
    }
    it1--;
    it2--;
    if(it1==l1.end())
    {
        if(*it1==*it2)
            return *it1;
        else
            return NULL;
    }
    else
    {
        if(*it1==*it2)
            return *it2;
        else
            return NULL;
    }
}

//BinaryTree
BinaryTreeNode* GetLastCommonNode_BinaryTree(BinaryTreeNode* root,BinaryTreeNode* node1,BinaryTreeNode* node2)
{
    if(root==NULL || node1==NULL || node2==NULL)
        return NULL;
    list<BinaryTreeNode*> l1;
    list<BinaryTreeNode*> l2;
    GetPath(root,node1,l1);
    GetPath(root,node2,l2);
    return GetFirstCommonNodeInList(l1,l2);
}


//-------测试代码------

BinaryTreeNode* CreateTree(const int* PreOrder,const int* InOrder,int n,BinaryTreeNode*& node1,BinaryTreeNode*& node2,int value1,int value2,BinaryTreeNode* parent)
{
    if(PreOrder==NULL || InOrder==NULL || n<=0)
        return NULL;
    BinaryTreeNode* root=new BinaryTreeNode(PreOrder[0]);
    if(root->value==value1)
        node1=root;
    if(root->value==value2)
        node2=root;
    int i=0;
    while(InOrder[i]!=PreOrder[0])
    {
        i++;
    }
    root->parent=parent;
    root->left=CreateTree(PreOrder+1,InOrder,i,node1,node2,value1,value2,root);
    root->right=CreateTree(PreOrder+i+1,InOrder+i+1,n-i-1,node1,node2,value1,value2,root);
    return root;
}

void PrintTree_Pre(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->value<<" ";
    PrintTree_Pre(root->left);
    PrintTree_Pre(root->right);
}

void test_BST()
{
    int Pre_Arr[]={5,3,2,1,4,6};
    int In_Arr[]={1,2,3,4,5,6};
    BinaryTreeNode* node1,*node2;
    int value1=4,value2=6;
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]),node1,node2,value1,value2,NULL);
    BinaryTreeNode* res=GetLastCommonNode_BST(root,node1,node2);
    if(res==NULL)
        cout<<"NULL"<<endl;
    else
        cout<<res->value<<endl;
}

void test_HasParent()
{
    int Pre_Arr[]={5,3,2,1,4,6};
    int In_Arr[]={1,2,3,4,5,6};
    BinaryTreeNode* node1,*node2;
    int value1=2,value2=1;
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]),node1,node2,value1,value2,NULL);
    BinaryTreeNode* res=GetLastCommonNode_HasParent(root,node1,node2);
    if(res==NULL)
        cout<<"NULL"<<endl;
    else
        cout<<res->value<<endl;
}

void test_BT()
{
    int Pre_Arr[]={5,3,2,1,4,6};
    int In_Arr[]={1,2,3,4,5,6};
    BinaryTreeNode* node1,*node2;
    int value1=5,value2=6;
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]),node1,node2,value1,value2,NULL);
    BinaryTreeNode* res=GetLastCommonNode_BinaryTree(root,node1,node2);
    if(res==NULL)
        cout<<"NULL"<<endl;
    else
        cout<<res->value<<endl;
}

void test()
{
    //test_BST();
    //test_HasParent();
    test_BT();
}

int main()
{
    test();
    return 0;
}

