#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}
void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}
void printAtLevelK(TreeNode<int>* root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data << endl;
		return;
	}
	for (int i = 0; i < root->children.size(); i++) {
		printAtLevelK(root->children[i], k - 1);
	}
}

int numNodes(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += numNodes(root->children[i]);
	}
	return ans;
}

int main() {
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	cout<<"level 2: "<<endl;
	printAtLevelK(root,2);
	// TODO delete the tree
		delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 a predefined tree input.

/*
Enter root data
1
Enter num of children of 1
3
Enter 0th child of 1
2
Enter 1th child of 1
3
Enter 2th child of 1
4
Enter num of children of 2
2
Enter 0th child of 2
5
Enter 1th child of 2
6
Enter num of children of 3
2
Enter 0th child of 3
7
Enter 1th child of 3
8
Enter num of children of 4
0
Enter num of children of 5
0
Enter num of children of 6
0
Enter num of children of 7
0
Enter num of children of 8
1
Enter 0th child of 8
7
Enter num of children of 9
0
1:2,3,4,
2:5,6,
5:
6:
3:7,8,
7:
8:9,
4:
*/

/*     1
    /  |  \
  2   3    4
 /\  / \
 5 6 7 8
       |
	   9
*/