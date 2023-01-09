/*
Find the closest element
Send Feedback
You are given a BST in the level order form and a target node K. You have to find a node having the minimum absolute difference with target value K and print the value of that minimum absolute difference.
Note: You have to return the value of the node having the minimum absolute difference with target value K, printing the minimum absolute difference is handled automatically.
Input Format
Line 1: Nodes in the level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2: Value of the target node K
Output Format:
The minimum absolute difference of a node with given target value K.
Constraints:
1<=Number of nodes<=1000
Sample Input:
9 4 17 3 6 -1 22 -1 -1 5 7 20 -1 -1 -1 -1 -1 -1 -1
18
Sample Output:
1
Explanation:
Here K=18, The node that has value nearest to K is 17 so it's difference with k is 1 is the answer.*/

#include<iostream>
#include<vector>
#include<climits>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};
BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
int leastmindiff(BinaryTreeNode<int> *root,int k, int Min = INT_MAX)
{
    if(root==NULL)
    {
        return 999;
    }
    if(root->data==k)
    {
        return 0;
    }
    Min = min(Min,abs(root->data-k));
    if(k<root->data)
    {
        int x=leastmindiff(root->left,k,Min);
        Min = min(Min,x);
    }
    else
    {
       int y=leastmindiff(root->right,k,Min);
       Min=min(Min,y);
    }
    return Min;
}
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    int k=18;
    cout<<leastmindiff(root,k);
}
//9 4 17 3 6 -1 22 -1 -1 5 7 20 -1 -1 -1 -1 -1 -1 -1
//18
// output -> 1