#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        left=right=NULL;
    }
};

void levelorderprint(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp=q.front();
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
// level order built

node * levelorderbuilt()
{
    int d;
    cin>> d;
    node* root =new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* current =q.front();
        q.pop();
        int c1, c2;
        cin>> c1>> c2; 

        if(c1!=-1)
        {
            current->left = new node(c1);   
            q.push(current->left);
        }
        if(c2!=-1)
        {
            current->right = new node(c2); 
            q.push(current->right);
        }
    }
    return root;

}
// O(n)

class Pair
{
    public:
    int inc;
    int exc;
};
Pair maxSubsetSum(node *root)
{
    Pair p;
    if(root==NULL)
    {
        p.inc=p.exc =0;
        return p;
    }
    Pair Left =maxSubsetSum(root->left);
    Pair Right =maxSubsetSum(root->right);

    p.inc =root->data +Left.exc +Right.exc; // if a include the root node , then i cant include the root->left and root->right
    p.exc=max(Left.inc , Left.exc) + max(Right.inc, Right.exc); // if i exclude the root node , then max sum can be get from either including or excluding the root->left + including or excluding the root->right

    return p;

}
//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
// level order built me input me level order jaise denge 
// in most of the subset problems -- we generally have an idea of whether to include this element or not .
// so same thing we will be applying in this.
int main()
{
//node *root= BuiltTree();
node *root =levelorderbuilt();
levelorderprint(root);
Pair p= maxSubsetSum(root);
cout<<"Max sum: " <<max(p.inc,p.exc)<<endl;
}