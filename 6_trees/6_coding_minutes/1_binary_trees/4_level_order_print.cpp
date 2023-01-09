/* todo : implement level order traversal 
expected output:
1
2 3
4 5 6
*/

#include<bits/stdc++.h>
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

void levelorderprint(Node*root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp=q.front();
        if(temp==NULL)
        {
            cout<<endl;
            q.pop();
            // insert a new null for the next level
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
int main()
{
Node *root= BuiltTree();
levelorderprint(root);
/*
1 
2 3
4 5 6
7
*/
}
 /*
     1
    / \
   2   \
  / \   3
 4   5   \
    /     6
   7
*/