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

void Serialize(BinaryTreeNode* root,vector<char>& v)
{
    if(root==NULL)
    {
        v.push_back('#');
        return;
    }
    v.push_back(root->value+'0');
    Serialize(root->left,v);
    Serialize(root->right,v);
}

void Deserialize(BinaryTreeNode** proot,const vector<char>& v,int& pos)
{
    if(pos>=v.size() || v[pos]=='#')
        return;
    BinaryTreeNode* node=new BinaryTreeNode(v[pos]-'0');
    *proot=node;
    Deserialize(&(node->left),v,++pos);
    Deserialize(&(node->right),v,++pos);
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
    int Pre_Arr[]={1,2,4,3,5,6};
    int In_Arr[]={4,2,1,5,3,6};
    vector<char> v;
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    Serialize(root,v);
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    BinaryTreeNode* res;
    int pos=0;
    Deserialize(&res,v,pos);
    Print_Pre(res);
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
