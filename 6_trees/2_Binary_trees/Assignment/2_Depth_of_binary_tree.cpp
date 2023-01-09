/*Depth of Binary Tree
Send Feedback
A rooted binary tree is called “nice”, if every node is either a leaf, or has exactly two children.
For example, the following tree is nice,
                           n
                         /   \
                        l     n
                             / \
                            n   l
                           / \
                          l   l
and the following tree is not,
                          n
                         / \
                       n     n
                      /
                     l
The leaves of a nice binary tree are labeled by the letter ‘l’, and other nodes are labeled by the letter ‘n’.
Given the pre-order traversal of a nice binary tree as a string, you are required to find the depth of the tree.
Output one line for each test case, containing a single integer, the depth of tree.
Sample Input 1:
                nlnll
Sample Output 1:
                2
Sample Input 2:
                nll
Sample Output 2:
                1
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
BinaryTreeNode<string>* takeInputLevelWise() {
	string rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == "e") {
		return NULL;
	}
	BinaryTreeNode<string>* root = new BinaryTreeNode<string>(rootData);
	queue<BinaryTreeNode<string>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<string>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		string leftChildData;
		cin >> leftChildData;
		if(leftChildData != "e")
		{
			BinaryTreeNode<string>* child = new BinaryTreeNode<string>(leftChildData);
			front->left = child;
			pendingNodes.push(child);

		}
		cout << "Enter right child of " << front->data << endl;
		string rightChildData;
		cin >> rightChildData;
		if(rightChildData != "e")
		{
			BinaryTreeNode<string>* child1 = new BinaryTreeNode<string>(rightChildData);
			front->right = child1;
			pendingNodes.push(child1);
		}
	}
	return root;
}

void printlevelwise(BinaryTreeNode<string> *root)
{
	queue<BinaryTreeNode<string> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		BinaryTreeNode<string> *front = pendingNodes.front();
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
int Depth_of_binary_tree(BinaryTreeNode<string>* root)
{
	if(root == NULL)
	{
		return -1;
	}
	int depth =-1;
	int d1 = Depth_of_binary_tree(root->left);
	 depth = max(depth,d1);
	 int d2 = Depth_of_binary_tree(root->right);
	 depth = max(depth,d2);
	 return depth+1;

}
int main() {
	
	BinaryTreeNode<string>* root = takeInputLevelWise();
	cout<<Depth_of_binary_tree(root)<<endl;
	printlevelwise(root);
	delete root;
}
// n l n e e l l e e e e 