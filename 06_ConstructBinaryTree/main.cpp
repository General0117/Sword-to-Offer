//
//Author:SmartBrave
//

#include<iostream>
#include<vector>
using namespace std;

typedef int data_type;

template<typename T>
struct BinaryTreeNode{
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T t=T()):data(t),left(NULL),right(NULL)
    {}
};

BinaryTreeNode<data_type>* ConstructBinaryTree(vector<data_type>::iterator vlr,vector<data_type>::iterator lvr,int size)
{
    if(size<=0)
        return NULL;
    BinaryTreeNode<data_type>* CurRoot=new BinaryTreeNode<data_type>(vlr[0]);
    vector<data_type>::iterator it=lvr;
    while(it!=lvr+size && *it!=CurRoot->data)
        it++;
    if(*it==CurRoot->data)
    {
        CurRoot->left=ConstructBinaryTree(vlr+1,lvr,it-lvr);
        CurRoot->right=ConstructBinaryTree(vlr+(it-lvr)+1,it+1,size-(it-lvr)-1);
    }
    return CurRoot;
}


//-------测试代码--------

void PrintBinaryTreePostOrder(BinaryTreeNode<data_type>* root)
{
    if(root==NULL)
        return;
    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
    cout<<root->data<<" ";
}

void test()
{
    data_type vlr_arr[]={1,2,4,7,3,5,6,8};
    data_type lvr_arr[]={4,7,2,1,5,3,8,6};
    vector<data_type> VLR;
    vector<data_type> LVR;
    int i;
    for(i=0;i<sizeof(vlr_arr)/sizeof(vlr_arr[0]);++i)
    {
        VLR.push_back(vlr_arr[i]);
        LVR.push_back(lvr_arr[i]);
    }
    BinaryTreeNode<data_type>* root=ConstructBinaryTree(VLR.begin(),LVR.begin(),VLR.size());
    PrintBinaryTreePostOrder(root);
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
