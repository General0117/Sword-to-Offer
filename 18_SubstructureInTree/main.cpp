#include<iostream>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),left(NULL),right(NULL)
    {}
};

bool HasSubTree(BinaryTreeNode* root1,BinaryTreeNode* root2)
{
    if(root1==NULL)
    {
        if(root2==NULL)
            return true;
        else
            return false;
    }
    if(root2==NULL)
        return true;
    if(root1->value==root2->value)
    {
        if(HasSubTree(root1->left,root2->left) &&
                HasSubTree(root1->right,root2->right))
        {
            return true;
        }
        else
        {
            if(HasSubTree(root1->left,root2) || HasSubTree(root1->right,root2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        if(HasSubTree(root1->left,root2) || HasSubTree(root1->right,root2))
        {
            return true;
        }
        else
        {
            return false;
        }
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

void test()
{
    int Pre_Arr1[]={1,2,4,8,5,3,6,7};
    int In_Arr1[]={8,4,2,5,1,6,3,7};

    int Pre_Arr2[]={2,4,8,6};
    int In_Arr2[]={8,4,2,6};

    BinaryTreeNode* root1=CreateTree(Pre_Arr1,In_Arr1,sizeof(Pre_Arr1)/sizeof(Pre_Arr1[0]));
    BinaryTreeNode* root2=CreateTree(Pre_Arr2,In_Arr2,sizeof(Pre_Arr2)/sizeof(Pre_Arr2[0]));
    if(HasSubTree(root1,root2))
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
}

int main()
{
    test();
    return 0;
}
