/*
Set Parent Pointer
Send Feedback
You are given elements of a binary search tree in level order form. The level order form is described in input format. You have to build that tree and print the preorder traversal of the tree. Please refer to output format for more details.
Input format :
The first line contains an integer that represents the size of array. Let the size of array be denoted by the symbol n. n elements are required to represent binary search tree in level order form. In level order form, an element at an index i is parent to elements at index 2*i+1 and 2*i+2. The index of left child and right child are 2*i+1 and 2*i+2 respectively. So, the following line contains n space separated integers, that represents the elements in level order form (If any node does not have left or right child, take -1 in its place)
Output Format :
Elements/ nodes are printed using preorder traversal. Each node is printed in a new line. The nodes are printed in the following format:
Data of left child “ => ” Data of node “[” Data of parent “]” “ <= ” Data of right child
If left child or right child is null, then it is to be represented by “.”. If the parent is null, then it is to be represented by “null”.
Sample Input 1:
19
50 25 75 12 37 62 87 -1 -1 30 40 -1 -1 -1 -1 -1 -1 -1 -1  
Sample Output 1:
25 => 50[null] <= 75
12 => 25[50] <= 37
. => 12[25] <= .
30 => 37[25] <= 40
. => 30[37] <= .
. => 40[37] <= .
62 => 75[50] <= 87
. => 62[75] <= .
. => 87[75] <= .
*/



#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
// pre order traversal
//Data of left child “ => ” Data of node “[” Data of parent “]” “ <= ” Data of right child
/*
25 => 50[null] <= 75
12 => 25[50] <= 37
. => 12[25] <= .*/
void preorder(BinaryTreeNode<int> *root,BinaryTreeNode<int> *parentPointer=NULL)
{
if(root == NULL)
{
    return;
}
if(root->left ==NULL and root->right ==NULL)
{
    cout<<"."<<"==>"<<root->data<<'['<<parentPointer->data<<']'<<"==>"<<"."<<endl;
}
else if(root->left ==NULL)
{
    cout<<"."<<"==>"<<root->data<<'['<<parentPointer->data<<']'<<"==>"<<root->right->data<<endl;
}
else if(root->right ==NULL)
{
    cout<<root->left->data<<"==>"<<root->data<<'['<<parentPointer->data<<']'<<"==>"<<"."<<endl;

}
else
{
    cout<<root->left->data<<"==>"<<root->data<<'['<<"NULL"<<']'<<"==>"<<root->right->data<<endl;
}
preorder(root->left,root);
preorder(root->right,root);

}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    preorder(root);
}