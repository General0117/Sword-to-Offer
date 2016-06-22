#include<iostream>
#include<vector>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),left(NULL),right(NULL)
    {}
};

//int GetCount(BinaryTreeNode* root)
//{
//    if(root==NULL)
//        return 0;
//    return GetCount(root->left)+GetCount(root->right)+1;
//}
//
//BinaryTreeNode* KthNode(BinaryTreeNode* root,unsigned k)
//{
//    if(root==NULL || k==0)
//        return NULL;
//    int LeftCount=GetCount(root->left);
//    if(LeftCount+1==k)
//        return root;
//    else if(LeftCount<k)
//        return KthNode(root->right,k-LeftCount-1);
//    else KthNode(root->left,k);
//}

BinaryTreeNode* _KthNode(BinaryTreeNode* root,unsigned int& k)
{
    if(root==NULL)
        return NULL;
    BinaryTreeNode* tmp=NULL;
    if(root->left!=NULL)
        tmp=_KthNode(root->left,k);
    if(tmp==NULL)
    {
        k--;
        if(k==0)
            return root;
        tmp=NULL;
        if(root->right!=NULL)
            tmp=_KthNode(root->right,k);
        if(tmp==NULL)
        {
            if(k==0)
                return root;
            else
                return NULL;
        }
        else
        {
            return tmp;
        }
    }
    else
        return tmp;
}

BinaryTreeNode* KthNode(BinaryTreeNode* root,unsigned int k)
{
    if(root==NULL || k==0)
        return NULL;
    return _KthNode(root,k);
}

//-------测试代码------

BinaryTreeNode* CreateTree(const int* PreOrder,const int* InOrder,int n)
{
    if(PreOrder==NULL || InOrder==NULL || n<=0)
        return NULL;
    BinaryTreeNode* root=new BinaryTreeNode(PreOrder[0]);
    int i=0;
    while(InOrder[i]!=PreOrder[0])
    {
        i++;
    }
    root->left=CreateTree(PreOrder+1,InOrder,i);
    root->right=CreateTree(PreOrder+i+1,InOrder+i+1,n-i-1);
    return root;
}

void Print_Pre(BinaryTreeNode* root)
{
    if(root==NULL)
        return;
    cout<<root->value<<" ";
    Print_Pre(root->left);
    Print_Pre(root->right);
}

void test()
{
    int Pre_Arr[]={5,3,2,4,7,6,8};
    int In_Arr[]={2,3,4,5,6,7,8};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    BinaryTreeNode* res=NULL;
    for(int i=1;i<8;++i)
    {
        res=KthNode(root,i);
        cout<<i<<"th: ";
        if(res==NULL)
            cout<<"NULL"<<endl;
        else
            cout<<res->value<<endl;
    }
}

int main()
{
    test();
    return 0;
}
