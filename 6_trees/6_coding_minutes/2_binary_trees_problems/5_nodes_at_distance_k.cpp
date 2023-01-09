
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
void printAtLevelK(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
}
int printNodesAtDistanceK(node* root, node *target, int k)
{
    // base case
    if(root==NULL)
    {
        return -1;
    }
    // reach the target node
    if(root==target)
    {
        printAtLevelK(target,k);
        return 0;
    }
    // other case 
    // we will check whether target node is present in the left subtree or right subtree
    // if its present in the left 
    int DL= printNodesAtDistanceK(root->left,target,k); // D that we got here 
    if(DL != -1)
    {
        // 2cases
        // print the current node
        if(DL +1==k)
        {
            cout<<root->data<<" ";
        }
        // or print somenodes in the rightsubtree
        else
        {
            printAtLevelK(root->right,k-2-DL);
        }
        return 1+DL; // returning 1 + D to its parent 
    }
    // if target node is present in the right
    int DR= printNodesAtDistanceK(root->right,target,k);
     if(DL != -1)
    {
        // 2cases
        // print the current node
        if(DL +1==k)
        {
            cout<<root->data<<" ";
        }
        // or print somenodes in the rightsubtree
        else
        {
            printAtLevelK(root->left,k-2-DR);
        }
        return 1+DR;
    }
    return -1; 

}
int main()
{

node* root= new node(1);
root->left= new node(2);
root->right= new node(3);
root->left->left= new node(4);
root->left->right= new node(5);
root->right->right= new node(6);
root->left->right->left= new node(7);
root->left->right->right= new node(8);
root->left->right->right->left= new node(9);
root->left->right->right->right= new node(10);
// target node 5
node * target =root->left->right;
int k=2;
printNodesAtDistanceK(root,target,k);
}
/*      1
       /  \
      2    3
     /  \    \
    4   5     6
       /  \
      7    8
          /  \
         9    10
  other case of this question
  5 is the target .. all the ancestors of 5 are 1 2
  [1,2]  
     N
 (1)/ \(1)
(x)|   |(D)
       5
  to check for nodes in other parts (excuding the down part) 
  we have to check for a distance
  x +1+1 +D =k 
  x= k-D-2  if for any node we got x=k-D-2 distance then that node will be selected 
  let us put the values for 2=N
  x=k-0-2
  x=k-2
   =2-2
   =0
  if for N, the target node is in its left subtree then N will call to its right subtree for checking the condition K-D-2

  for N =1 ,we have  D=1 (like 5 will tell 2 that i am distance zero from u , and 2 will tell its parent that target node is at distance 1 from u)
  D=1 , if(D+1==k) that means N is itseft k distance away, 
  so we dont need to call on the other subpart 
*/