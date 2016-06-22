#include<iostream>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),left(NULL),right(NULL)
    {}
};

void MirrorRecursively(BinaryTreeNode* root)
{
    if(root==NULL)
        return;
    swap(root->left,root->right);
    MirrorRecursively(root->left);
    MirrorRecursively(root->right);
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

void test()
{
    int Pre_Arr[]={1,2,4,8,5,3,6,7};
    int In_Arr[]={8,4,2,5,1,6,3,7};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    PrintTree_Pre(root);
    cout<<endl;
    MirrorRecursively(root);
    PrintTree_Pre(root);
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
