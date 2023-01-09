#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        left=right=NULL;
    }
};
// builting a tree by functional call
Node *BuiltTree()
{
    int rootdata;
    cin>> rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    Node *root = new Node(rootdata);
    root->left=BuiltTree();
    root->right=BuiltTree();
    return root;
}

void printPreorder(Node *root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    printPreorder(root->left); 
    printPreorder(root->right);
}
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
int main()
{
Node *root= BuiltTree();
printPreorder(root);
}
//1 2 4 5 7 3 6 
     /*
     1
    / \
   2   \
  / \   3
 4   5   \
    /     6
   7
*/