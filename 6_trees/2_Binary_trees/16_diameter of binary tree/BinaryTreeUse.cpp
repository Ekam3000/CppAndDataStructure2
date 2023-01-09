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
int height(	BinaryTreeNode<int>* root)
{
  if(root == NULL) {
    return 0;
  }
  int h=-1;
  int h1 = height(root->left);
  h = max(h, h1);
  int h2 = height(root->right);
  h = max(h, h2);
  return h+1;
  // return 1+ max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int option1 = height(root->left) + height(root->right); // if tree is both side spreaded 
	int option2 = diameter(root->left); // if tree is left side spreaded
	int option3 = diameter(root->right);// if tree is right side spreaded
	return max(option1, max(option2, option3)); // so if tree me tino possibilities possible hai then tino options mese jo max hoga vo return ho jaye ga 
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
	/*int in[] = {4,2,5,1,8,6,9,3,7};
	int pre[] = {1,2,4,5,3,6,8,9,7};
	BinaryTreeNode<int>* root = buildTree(in, pre, 9);
	*/
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	cout<<diameter(root)<<endl;
	delete root;
}

