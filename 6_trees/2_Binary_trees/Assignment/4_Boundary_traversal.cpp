/*Boundary Traversal
Send Feedback
Given a binary tree having N nodes, print its boundary traversal.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Boundary traversal (separated by space)
Constraints :
1 <= N <= 10^5
Sample Input 1 :
1 2 3 -1 -1 -1 -1
Sample Output 1 :
1 2 3
Sample Input 2 :
1 2 3 4 5 7 -1 -1 -1 6 -1 -1 8 -1 -1 -1 -1
Sample Output 2 :
1 2 4 6 8 7 3
*/
#include<iostream>
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
void leftTree(BinaryTreeNode<int>* root, vector<int> & v)
{
	if(root==NULL)
	{
		return;
	}
	if(root->left != NULL)
	{
      v.push_back(root->data);
	  leftTree(root->left,v);
	}
	else if(root->right != NULL)
	{
		v.push_back(root->data);
	    leftTree(root->right,v);
	}
}
void leaf(BinaryTreeNode<int>* root, vector<int> & v)
{
	if(root==NULL)
	{
		return;
	}
	leaf(root->left,v);
	if(root->left == NULL && root->right == NULL)
	{
     v.push_back(root->data);
	}
	leaf(root->right,v);
}
void rightTree(BinaryTreeNode<int>* root, vector<int> & v)
{
	if(root==NULL)
	{
		return;
	}
	if(root->right != NULL)
	{
		rightTree(root->right,v);
		v.push_back(root->data);
	}
	else if(root->left != NULL)
	{
		rightTree(root->left,v);
		v.push_back(root->data);
	}
}
void BoundaryTraversal(BinaryTreeNode<int>* root){
	vector<int> v;
	v.push_back(root->data);
	leftTree(root->left, v);
	leaf(root,v);
	rightTree(root->right, v);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

int main() {	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	//printlevelwise(root);
	BoundaryTraversal(root);
	delete root;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
/*
level order inputs-->
     1
   /   \
  2     3
 / \   / \
4  5  6   7
     / \
    8   9
*/