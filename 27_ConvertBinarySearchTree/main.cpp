#include<iostream>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),left(NULL),right(NULL)
    {}
};

void _Convert(BinaryTreeNode* root,BinaryTreeNode*& tail)
{
    if(root==NULL)
        return;
    BinaryTreeNode* cur=root;
    _Convert(cur->left,tail);
    cur->left=tail;
    if(tail!=NULL)
        tail->right=cur;
    tail=root;
    _Convert(root->right,tail);
}

BinaryTreeNode* Convert(BinaryTreeNode* root)
{
    if(root==NULL)
        return NULL;
    BinaryTreeNode* head=root;
    while(head->left!=NULL)
        head=head->left;
    BinaryTreeNode* tail=NULL;
    _Convert(root,tail);
    return head;
}


//-------测试代码-------
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
void PrintList(BinaryTreeNode* head)
{
    if(head==NULL)
        return;
    BinaryTreeNode* cur=head;
    while(cur!=NULL)
    {
        cout<<cur->value<<" ";
        cur=cur->right;
    }
    cout<<endl;
}
void test()
{
    int Pre_Arr[]={5,2,0,1,4,3,6,7};
    int In_Arr[]={0,1,2,3,4,5,6,7};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    PrintTree_Pre(root);
    cout<<endl;
    PrintList(Convert(root));
}

int main()
{
    test();
    return 0;
}
