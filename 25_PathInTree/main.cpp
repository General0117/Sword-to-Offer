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

void _FindPath(BinaryTreeNode* root,int sum,vector<int>& v,int cursum)
{
    if(root==NULL)
        return;
    cursum+=root->value;
    v.push_back(root->value);
    if(cursum==sum && root->left==NULL && root->right==NULL)
    {
        vector<int>::iterator iter=v.begin();
        for(;iter!=v.end();++iter)
        {
            cout<<*iter<<" ";
        }
        cout<<endl;
    }
    else
    {
        _FindPath(root->left,sum,v,cursum);
        _FindPath(root->right,sum,v,cursum);
    }
    v.pop_back();
    return;
}

void FindPath(BinaryTreeNode* root,int sum)
{
    vector<int> v;
    _FindPath(root,sum,v,0);
}

//-----测试代码-------
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
    int Pre_Arr[]={10,5,4,7,12};
    int In_Arr[]={4,5,7,10,12};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    FindPath(root,22);
}

int main()
{
    test();
    return 0;
}
