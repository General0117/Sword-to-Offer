#include<iostream>
using namespace std;

struct BinaryTreeNode{
    float value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(float data=float()):value(data),left(NULL),right(NULL)
    {}
};

bool _isSymmetrical(BinaryTreeNode* left,BinaryTreeNode* right)
{
    if(left==NULL && right==NULL)
        return true;
    if(left==NULL || right==NULL)
        return false;
    if((int)(left->value)==(int)(right->value))
        return _isSymmetrical(left->left,right->right) && _isSymmetrical(left->right,right->left);
    else
        return false;
}
bool isSymmetrical(BinaryTreeNode* root)
{
    if(root==NULL)
        return true;
    return _isSymmetrical(root->left,root->right);
}

//-------测试代码------

BinaryTreeNode* CreateTree(const float* PreOrder,const float* InOrder,int n)
{
    if(PreOrder==NULL || InOrder==NULL || n<=0)
        return NULL;
    BinaryTreeNode* root=new BinaryTreeNode(PreOrder[0]);
    int i=0;
    while((int)InOrder[i]!=(int)PreOrder[0])
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
    cout<<(int)(root->value)<<" ";
    PrintTree_Pre(root->left);
    PrintTree_Pre(root->right);
}

void PrintTree_In(BinaryTreeNode* root)
{
    if(root==NULL)
        return ;
    PrintTree_In(root->left);
    cout<<(int)(root->value)<<" ";
    PrintTree_In(root->right);
}

void test()
{
    float Pre_Arr1[]={8,6.1,5.1,7.1,6.2,7.2,5.2};
    float In_Arr1[]={5.1,6.1,7.1,8,7.2,6.2,5.2};
    float Pre_Arr2[]={8,6,5.1,7.1,9,7.2,5.2};
    float In_Arr2[]={5.1,6,7.1,8,7.2,9,5.2};
    float Pre_Arr3[]={7.1,7.2,7.3,7.4,7.5,7.6};
    float In_Arr3[]={7.3,7.2,7.4,7.1,7.6,7.5};
    BinaryTreeNode* root1=CreateTree(Pre_Arr1,In_Arr1,sizeof(Pre_Arr1)/sizeof(Pre_Arr1[0]));
    BinaryTreeNode* root2=CreateTree(Pre_Arr2,In_Arr2,sizeof(Pre_Arr2)/sizeof(Pre_Arr2[0]));
    BinaryTreeNode* root3=CreateTree(Pre_Arr3,In_Arr3,sizeof(Pre_Arr3)/sizeof(Pre_Arr3[0]));
    PrintTree_Pre(root1);
    cout<<"\t\t";
    PrintTree_In(root1);
    cout<<endl;
    PrintTree_Pre(root2);
    cout<<"\t\t";
    PrintTree_In(root2);
    cout<<endl;
    PrintTree_Pre(root3);
    cout<<"\t\t";
    PrintTree_In(root3);
    cout<<endl;
    cout<<isSymmetrical(root1)<<endl;
    cout<<isSymmetrical(root2)<<endl;
    cout<<isSymmetrical(root3)<<endl;
}

int main()
{
    test();
    return 0;
}
