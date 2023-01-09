#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
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
BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}// 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}
// binary tree ki implementation puri linked list ki feel deta hai bus iske do further nodes hai left and right , but linked list me ek hi thi.
int main() {
  /*BinaryTreeNode<int>* root =   new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    B inaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	root->left = node1;
	root->right = node2;
	*/
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
	delete root;
}

/*

// 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1


Enter data
1
Enter data
2
Enter data
4
Enter data
-1
Enter data
-1
Enter data
5
Enter data
6
Enter data
-1
Enter data
-1
Enter data
7
Enter data
-1
Enter data
-1
Enter data
3
Enter data
8
Enter data
-1
Enter data
-1
Enter data
-1

1:L2R3
2:L4R5
4:
5:L6R7
6:
7:
3:L8
8:

*/
