#include<iostream>
#include<stdlib.h>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),left(NULL),right(NULL)
    {}
};

//int Depth(BinaryTreeNode* root)
//{
//    if(root==NULL)
//        return 0;
//    int LeftDepth=Depth(root->left);
//    int RightDepth=Depth(root->right);
//    return LeftDepth>RightDepth?LeftDepth+1:RightDepth+1;
//}
//
//bool IsBalancedTree(BinaryTreeNode* root)
//{
//    if(root==NULL)
//        return true;
//    int LeftDepth,RightDepth;
//    LeftDepth=Depth(root->left);
//    RightDepth=Depth(root->right);
//    if(abs(LeftDepth-RightDepth)<=1)
//        return true;
//    else
//        return false;
//}
bool _IsBalancedTree(BinaryTreeNode* root,int& depth)
{
    if(root==NULL)
    {
        depth=0;
        return true;
    }
    int left,right;
    if(_IsBalancedTree(root->left,left) && _IsBalancedTree(root->right,right))
    {
        int diff=right-left;
        if(diff>=-1 && diff <=1)
        {
            depth=left>right?left+1:right+1;
            return true;
        }
    }
    return false;
}

bool IsBalancedTree(BinaryTreeNode* root)
{
    int depth=0;
    return _IsBalancedTree(root,depth);
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
    //int Pre_Arr[]={1,2,4,8,5,3,6,7};
    //int In_Arr[]={8,4,2,5,1,6,3,7};
    int Pre_Arr[]={1,2,3,4,5,6,7,8};
    int In_Arr[]={8,7,6,5,4,3,2,1};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    cout<<IsBalancedTree(root)<<endl;
}

int main()
{
    test();
    return 0;
}
