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

//void Print(BinaryTreeNode* root)
//{
//    if(root==NULL)
//        return;
//    queue<BinaryTreeNode*> q;
//    q.push(root);
//    int nextLevel=0;
//    int toBePrint=1;
//    BinaryTreeNode* tmp=NULL;
//    while(!q.empty())
//    {
//        tmp=q.front();
//        q.pop();
//        cout<<tmp->value<<" ";//这种方法在每个节点后面会打印一个空格
//        toBePrint--;
//        if(tmp->left!=NULL)
//        {
//            nextLevel++;
//            q.push(tmp->left);
//        }
//        if(tmp->right!=NULL)
//        {
//            nextLevel++;
//            q.push(tmp->right);
//        }
//        if(toBePrint==0)
//        {
//            toBePrint=nextLevel;
//            nextLevel=0;
//            cout<<endl;
//        }
//    }
//}

void Print(BinaryTreeNode* root)
{
    if(root==NULL)
        return;
    queue<BinaryTreeNode*> q;
    q.push(root);
    q.push(NULL);
    BinaryTreeNode* tmp=NULL;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp==NULL)
        {
            q.push(NULL);
            cout<<endl;
        }
        else
        {
            if(tmp->left!=NULL)
                q.push(tmp->left);
            if(tmp->right!=NULL)
                q.push(tmp->right);
            cout<<tmp->value<<" ";
        }
        if(q.size()==1)
            break;
    }
    cout<<endl;
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
    int Pre_Arr[]={8,6,5,7,10,9,11};
    int In_Arr[]={5,6,7,8,9,10,11};
    BinaryTreeNode* root=CreateTree(Pre_Arr,In_Arr,sizeof(Pre_Arr)/sizeof(Pre_Arr[0]));
    Print(root);
}

int main()
{
    test();
    return 0;
}
