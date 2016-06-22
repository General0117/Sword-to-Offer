#include<iostream>
#include<queue>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),left(NULL),right(NULL)
    {}
};

int Depth(BinaryTreeNode* root)
{
    if(root==NULL)
        return 0;
    int LeftDepth=Depth(root->left);
    int RightDepth=Depth(root->right);
    return LeftDepth>RightDepth?LeftDepth+1:RightDepth+1;
}

//------测试代码------
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
void test()
{
    int Pre_Arr[]={1,2,4,8,5,3,6,7};
    int In_Arr[]={8,4,2,5,1,6,3,7};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    cout<<Depth(root)<<endl;
}

int main()
{
    test();
    return 0;
}
