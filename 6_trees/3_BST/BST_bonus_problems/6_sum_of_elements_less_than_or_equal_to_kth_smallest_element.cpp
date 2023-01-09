/*
Sum of elements less than or equal to Kth smallest element
Send Feedback
You are given an integer K and elements of a binary search tree in level order form. You have to return the sum of elements which are smaller than or equal to Kth smallest element of the tree.
Input format :
The first line of input contains an integer that denotes the value of K. The following line contains an integer that represents the size of array. Let the size of array be denoted by the symbol n. n elements are required to represent binary search tree in level order form. In level order form, an element at an index i is parent to elements at index 2*i+1 and 2*i+2. The index of left child and right child are 2*i+1 and 2*i+2 respectively. So, the following line contains n space separated integers, that represents the elements in level order form (If any node does not have left or right child, take -1 in its place).
Output Format :
Elements/ nodes are printed using inorder traversal. Each node is printed in a new line. The nodes are printed in the following format:
Data of left child “ => ” Data of node “[” Data of parent “]” “=>” Data of right child
If left child or right child is null, then it is to be represented by “.”. If the parent is null, then it is to be represented by “null”.
Sample Input 1:
3
15
50 25 75 12 37 62 87 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
74
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
// static vector<int> v;
//  the elements of the inorder are placed in the incresing order
int sumLessOrEqualToK(BinaryTreeNode<int> *root, int k, int &count)
{
    if (root == NULL)
    {
        return 0;
    }
    if(count> k)
    {
        return 0;
    }
    int res = sumLessOrEqualToK(root->left, k, count);
    if (count >= k)
    {
        return res;
    }
    res += root->data;
    count++;
    if (count >= k)
    {
        return res;
    }
    return res + sumLessOrEqualToK(root->right, k, count);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k = 3;
    int count=0;
    cout<<sumLessOrEqualToK(root, k, count);
    /*for(int i=0;i<v.size();i++)
    {
        cout<<" "<<v[i];
    }*/
    // this for loop can be used if don't use sum as a variable in the recursive function
}
// k=3.
// 50 25 75 12 37 62 87 -1 -1 -1 -1 -1 -1 -1 -1