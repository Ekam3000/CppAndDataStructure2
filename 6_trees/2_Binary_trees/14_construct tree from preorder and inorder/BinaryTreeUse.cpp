#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

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



// root to hame preorder ke starting element se mil ajye ga 
// and by recursion hame left subtree aur right subtree bnana 
// left subtree ke liye hame left inorder(starting and ending element of left part of inorder) aur left preorder(starting and ending element of left part of preorder) chahiye
// right subtree ke liye hame right inorder(starting and ending element of right part of inorder) aur right preorder(starting and ending element of right part of preorder) chahiye


// important
//This is so because we cannot separate the left sub-tree
// and right sub-tree using the pre-order or post-order traversal 
//alone
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) { // can also apply for pre order
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
	int lPreE = lInE - lInS + lPreS; // as lInE - lInS = lPreE -iInS
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
	//int in[] = {4,2,5,1,8,6,9,3,7};
	int in[] = {9,3,15,20,7};
	//int pre[] = {1,2,4,5,3,6,8,9,7};
	int pre[] = {3,9,20,15,7};
	BinaryTreeNode<int>* root = buildTree(in, pre, 9);
	
	printTree(root);
	
	delete root;
}

/*
    1
  /   \
 2     3
/ \   / \
4  5 6   7
    / \ 
   8   9

*/

/*
why not only inorder is used ?

suppose 1 2 3 is the inorder 
so 1 and    2 
    \      / \
	 2    1   3
	  \
	   3
are both BT for the given inorder ,so only inorder is not sufficient saath me pre ya postorder bhi chahiye */
