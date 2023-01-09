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

void printlevelwise(BinaryTreeNode<int> *root)
{
	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		cout << front->data<<":";
		pendingNodes.pop();
                if(front->left != NULL)
                {
			cout<<"L" <<front->left->data<<" ";
			pendingNodes.push(front->left);
                }
                if(front->right != NULL)
                {
	        cout<<"R" <<front->right->data<<" ";
			pendingNodes.push(front->right);
                }
		cout<<endl;
	}
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

int main() {
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printlevelwise(root);
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