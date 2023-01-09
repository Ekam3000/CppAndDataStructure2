#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node * left;
    Node *right;

    Node(int key)
    {
        this->key =key;
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

void printInorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    // left, root, right
    printInorder(root->left); cout<<root->key<<",";
    printInorder(root->right);

}

void printRoot2LeafPaths(Node* root, vector<int> & path)
{

    if(root==NULL)
    {
        return;

    }
    if(root->left ==NULL and root->right==NULL)
    {
        // print the vector
        for(int node : path)
        {
            cout<<node<<"->";
        }
    
        cout<<root->key<<" ";
            cout<<endl;
        return;
    }
    // rec case
    path.push_back(root->key);
    printRoot2LeafPaths(root->left,path);
    printRoot2LeafPaths(root->right,path);
    // backtracking
    path.pop_back(); // when u are going back from a node , backtracking is happening
    return;
}

void printPreorder(Node *root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->key<<" ";
    printPreorder(root->left); 
    printPreorder(root->right);
}
int main()
{
    Node * root =BuiltTree();
    printPreorder(root);
    cout<<endl;
   
    printInorder(root); 
    cout<<endl;
    vector<int> path;
    printRoot2LeafPaths(root,path);
     
    return 0;
}