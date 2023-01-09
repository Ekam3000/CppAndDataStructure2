/*
Construct BST from level order
Send Feedback
You are given level order traversal of a Binary Search Tree in N-sized array, you have to construct a BST from this level order traversal.
Input Format:
The first line of input contains the number of nodes present in the BST. The following line of input elements of the N-sized array containing the level order traversal of BST.
Output Format:
The output contains the constructed tree where the preorder traversal of the BST is printed.
Constraints:
1<=Numberof nodes<=1000
Sample Input:
6
1 3 4 6 7 8
Sample Output:
1 3 4 6 7 8*/


#include<iostream>
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

void printlevelwise(BinaryTreeNode<int> *root)
{
  queue<BinaryTreeNode<int> *> pendingNodes;
  cout << root->data << endl;
  pendingNodes.push(root);
  int n = 1;
  int count = 0;
  while (pendingNodes.size() != 0)
  {
    for (int i = 0; i < n; i++)
    {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
      if (front->left != NULL)
      {
        cout << front->left->data << " ";
        pendingNodes.push(front->left);
        count++;
      }
      if (front->right != NULL)
      {
        cout << front->right->data << " ";
        pendingNodes.push(front->right);
        count++;
      }
    }
    cout << endl;
    n = count;
    count = 0;
  }
}

BinaryTreeNode<int > *construct_BST(BinaryTreeNode<int> * & root, int ele) {
        if(!root)
             return root = new BinaryTreeNode<int>(ele);
        if(root->data > ele)
             root->left=construct_BST (root->left, ele);
         else
             root->right =construct_BST(root->right, ele);
         return root;
}
 BinaryTreeNode<int> * buildBST (vector<int> pre) {
         BinaryTreeNode<int> *root =NULL;
         for (auto x : pre)
             construct_BST(root, x);
         return root;
 }
 
int main()
{
    
   vector<int> v = {1 ,3, 4, 6, 7, 8};
	BinaryTreeNode<int>* root = buildBST( v);
	printlevelwise(root);
    return 0;
}
// 1 3 4 6 7 8
// 7 4 12 2 