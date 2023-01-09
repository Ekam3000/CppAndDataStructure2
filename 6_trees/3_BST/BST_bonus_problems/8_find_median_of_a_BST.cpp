/*
Find median of a BST
Send Feedback
You are given a BST, return the integral part of the median of the given BST.
If the number of nodes are even, then median=((n/2)th node+(n/2+1)th node)/2
If the number of nodes are odd, then median=(n/2)th node
Note: The time complexity should be O(n) and space complexity should be O(1).
Input Format:
The first line of input contains number of nodes present in BST and the second line of the input contains the values of the nodes present in BST.
Output Format:
The only line of output contains the median of the given BST.
Constraints:
1<Number of node<=1000
Sample Input:
7
5 3 7 2 4 6 8
Sample Output:
5
Explanation:
The given BST is:
                     5
                   /    \
                 3        7
                /  \     /  \
               2    4   6    8
Sorted BST: 2 3 4 5 6 7 8
Number of nodes are odd, so median=5
*/
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
static vector<int> v;
void Inorder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
Inorder(root->left);
v.push_back(root->data);
Inorder(root->right);
}
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    Inorder(root);
    if(v.size()%2==0)
    {
        cout<<(v[v.size()/2]+v[(v.size()+1)/2])/2<<endl;
    }
    else
    {
        cout<<v[v.size()/2]<<endl;
    }
}
//5 3 7 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1 