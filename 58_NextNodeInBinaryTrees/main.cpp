#include<iostream>
using namespace std;

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data=int()):value(data),parent(NULL),left(NULL),right(NULL)
    {}
};

BinaryTreeNode* GetNext(BinaryTreeNode* node)
{
    if(node==NULL)
        return NULL;
    if(node->right!=NULL)
    {
        node=node->right;
        while(node->left!=NULL)
        {
            node=node->left;
        }
        return node;
    }
    else
    {
        if(node->parent==NULL)
            return NULL;
        else
        {
            BinaryTreeNode* father=node->parent;
            while(father!=NULL && father->right==node)
            {
                node=father;
                father=father->parent;
            }
            return father;
        }
    }
}



//-------测试代码------

BinaryTreeNode* CreateTree(const int* PreOrder,const int* InOrder,int n,BinaryTreeNode* father)
{
    if(PreOrder==NULL || InOrder==NULL || n<=0)
        return NULL;
    BinaryTreeNode* root=new BinaryTreeNode(PreOrder[0]);
    int i=0;
    while(InOrder[i]!=PreOrder[0])
    {
        i++;
    }
    root->parent=father;
    root->left=CreateTree(PreOrder+1,InOrder,i,root);
    root->right=CreateTree(PreOrder+i+1,InOrder+i+1,n-i-1,root);
    return root;
}

void PrintTree_In(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    PrintTree_In(root->left);
    cout<<root->value<<" ";
    PrintTree_In(root->right);
}

void visit(BinaryTreeNode* root)
{
    if(root==NULL)
        return;
    visit(root->left);
    cout<<"cur node: "<<root->value<<"  next node: ";
    BinaryTreeNode* res=GetNext(root);
    if(res==NULL)
        cout<<"NULL"<<endl;
    else
        cout<<res->value<<endl;
    visit(root->right);
}

void test()
{
    int Pre_Arr[]={1,2,4,8,5,3,6,7};
    int In_Arr[]={8,4,2,5,1,6,3,7};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]),NULL);
    PrintTree_In(root);
    cout<<endl;
    visit(root);
}

int main()
{
    test();
    return 0;
}
