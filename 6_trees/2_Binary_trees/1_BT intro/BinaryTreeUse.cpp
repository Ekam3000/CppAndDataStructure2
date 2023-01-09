#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int main() {
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	root->left = node1;
	root->right = node2;
	delete root;
}
/*
  1      1
 /  and   \
2          2 
these are two different trees
*/
