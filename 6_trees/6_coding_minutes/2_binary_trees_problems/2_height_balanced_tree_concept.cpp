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
pair<int,bool> isHeightBalanced(node * root)
{
    pair<int,bool> p, Left, Right;
    if(root==NULL)
    {
        p.first= 0;
        p.second=true;
        return p;
    }
    // rec case
    Left= isHeightBalanced(root->left);
    Right= isHeightBalanced(root->right);
    int height = max(Left.first,Right.first) + 1;  
    if(abs(Left.first-Right.first)<=1 and Left.second and Right.second)
    {
        return make_pair(height,true);
    }
          return make_pair(height,false);

}
//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
// level order built me input me level order jaise denge 
int main()
{
//node *root= BuiltTree();
node *root =levelorderbuilt();
pair<int,bool> p =isHeightBalanced(root);
if(p.second){
    cout<<" yes , height balanced"<<endl;
}
else
{
cout<<" no , height balanced"<<endl;
}
// 1 2 4 -1 -1  5 7 -1 -1 8 9 -1 -1  10 -1 -1  3 -1 6 -1 -1
}
