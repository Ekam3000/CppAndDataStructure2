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

Node *insert(Node *root, int key)
{
    if(root==NULL)
    {
        return new Node(key);
    }
    // rec case
    if(key<root-> key)
    {
        root->left= insert(root->left,key);
    }
    else{
         root->right= insert(root->right,key);
    }
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
// node inorder successor
// for inorder successor of a node look for the right subtree 
// go to extreme left of right subtree
Node * inorderSucc(Node *root, Node * target)
{
    // if right subtree
    if(target->right != NULL)
    {
        Node * temp = target->right;
        while(temp->left != NULL) 
        {
            temp=temp->left;
        }
        return temp;
    }
    // otherwise , if right subtree doesn't exist ,then we will cover a path from root(the initial first node) to target node
    Node *temp =root;
    Node * succ =NULL;
    while(temp != NULL)
    {
        if(temp->key > target->key) 
        {
            succ =temp;
            temp=temp->left; // means ab hum dekhe ge ki hame temp->key se koi aur choti value mil sakte for the successor ?
        }
        else if(temp->key < target->key) 
        {
            temp=temp->right;
        }
        else{
           break; // if we reach the target node 
        }
    }
    return succ;
}
int main()
{
    Node * root =NULL;
    int arr[]={8,3,10,1,6,14,4,7,13};
    for(int x: arr)
    {
        root =insert(root,x);
    }
    // test our ccode
    Node * t1 = root->left->right->right;
    Node *t2 =root->right;
    cout<<"Inorder succ of 7 is"<<inorderSucc(root,t1)->key<<endl;
    cout<<"Inorder succ of 10 is"<<inorderSucc(root,t2)->key<<endl;
    printInorder(root); 
    return 0;
}