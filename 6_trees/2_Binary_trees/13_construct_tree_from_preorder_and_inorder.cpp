/*

Code: Construct Tree from Preorder and Inorder
Send Feedback
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 



*/
#include <iostream>
#include <queue>
using namespace std;

template<typename T>
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

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}
	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}
	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS; // as lInE - lInS = lPreE -lpreS
	int rInS = rootIndex + 1;
	int rInE = inE;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE); // jaise binary tree bnane ke liye liye Pre and In chahiye the , vaise hi left subtree ke liye lPre and lIn chahiye .
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	/*
		 BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
		 BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
		 BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
		 root->left = node1;
		 root->right = node2;
	*/
	int in[] = {4,2,5,1,8,6,9,3,7};
	int pre[] = {1,2,4,5,3,6,8,9,7};
	BinaryTreeNode<int>* root = buildTree(in, pre, 9);
	printTree(root);
	delete root;
}