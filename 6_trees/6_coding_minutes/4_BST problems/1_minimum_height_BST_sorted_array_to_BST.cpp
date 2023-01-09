#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int find;
    Node * left;
    Node *right;

    Node(int key)
    {
        this->find =key;
        left=right=NULL;
    }
};


void printInorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    // left, root, right
    printInorder(root->left); cout<<root->find<<",";
    printInorder(root->right);

}
Node* sortedArrayToBST(vector<int> arr, int start, int end) 
{ 
    //Return Null if s > e, because no array elements are there
    if (start > end) 
        return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    Node *root = new Node(arr[mid]); 
  
    //create left & right subtrees recursively
    root->left = sortedArrayToBST(arr, start, mid - 1); 
    root->right = sortedArrayToBST(arr, mid + 1, end); 

    return root; 
} 
int main()
{
    Node * root =NULL;
    vector<int> arr={1,2,3,4,5,6,7};
    int n=arr.size();
    root =sortedArrayToBST(arr, 0 , n-1);
    printInorder(root);
    return 0;
}