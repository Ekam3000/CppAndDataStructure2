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
int replaceWithSum(node*root)
{
    // base case 
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL and root->right==NULL)
    {
        return root->data;
    }
    // recursive case
    int sum= replaceWithSum(root->left);
    sum += replaceWithSum(root->right);
    int temp= root->data;
    root->data= sum;
    return root->data +temp;
    /*int sum=0;
    sum+= replaceWithSum(root->left);
    sum+= replaceWithSum(root->right);
    int temp= root->data;
    root->data= sum;
    return root->data +temp;*/
   /* int LS= replaceWithSum(root->left);
    int RS= replaceWithSum(root->right);
    int temp= root->data;
    root->data= LS+RS;
    return root->data +temp;*/
}
//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
// level order built me input me level order jaise denge 
int main()
{
//node *root= BuiltTree();
node *root =levelorderbuilt();
replaceWithSum(root);
levelorderprint(root);
}