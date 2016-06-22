#include<iostream>
#include<stack>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),left(NULL),right(NULL)
    {}
};

void Print(BinaryTreeNode* root)
{
    if(root==NULL)
        return;
    stack<BinaryTreeNode*> sLeftToRight;
    stack<BinaryTreeNode*> sRightToLeft;
    sLeftToRight.push(root);
    BinaryTreeNode* tmp=NULL;
    while((!sLeftToRight.empty()) || (!sRightToLeft.empty()))
    {
        while(!sLeftToRight.empty())
        {
            tmp=sLeftToRight.top();
            sLeftToRight.pop();
            if(tmp->left!=NULL)
                sRightToLeft.push(tmp->left);
            if(tmp->right!=NULL)
                sRightToLeft.push(tmp->right);
            cout<<tmp->value<<" ";
        }
        cout<<endl;
        while(!sRightToLeft.empty()) 
        {
            tmp=sRightToLeft.top();
            sRightToLeft.pop();
            if(tmp->right!=NULL)
                sLeftToRight.push(tmp->right);
            if(tmp->left!=NULL)
                sLeftToRight.push(tmp->left);
            cout<<tmp->value<<" ";
        }
        cout<<endl;
    }
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
    cout<<(root->value)<<" ";
    PrintTree_Pre(root->left);
    PrintTree_Pre(root->right);
}

void test()
{
    int Pre_Arr[]={1,2,4,8,9,5,10,11,3,6,12,13,7,14,15};
    int In_Arr[]={8,4,9,2,10,5,11,1,12,6,13,3,14,7,15};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    Print(root);
}

int main()
{
    test();
    return 0;
}
