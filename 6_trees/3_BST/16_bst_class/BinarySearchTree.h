#include "BinaryTreeNode.h"
class BST {
	BinaryTreeNode<int>* root;
	public:
	BST() {
		root = NULL;
	}
	~BST() {
		delete root;
	}
	private:
	bool hasData(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			return false;
		}
		if (node->data == data) {
			return true;
		} else if (data < node->data) {
			return hasData(data, node->left);
		} else {
			return hasData(data, node->right);
		}
	}
	public:
	bool hasData(int data) {  // ye function ko sirf data provade karna hai main function ke through , ye aage root node ko call kare ga which further calls other sub nodes
		return hasData(data, root);
	}
};
