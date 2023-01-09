#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
TreeNode<int> *takeInput()
{
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		TreeNode<int> *child = takeInput();
		root->children.push_back(child);
	}
	return root;
}
void printTree(TreeNode<int> *root)
{
	if (root == NULL)
	{
		return ;
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++)
	{
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++)
	{
		printTree(root->children[i]);
	}
}
int numNodes(TreeNode<int> *root)
{
	if (root == NULL) {
		return 0;
	}
	int ans = 1; // if root is the only node then ans is 1
	// rest all work is done by recursion 
	
	for (int i = 0; i < root->children.size(); i++)
	{
		ans += numNodes(root->children[i]); // we will just add 1 i.e stored by ans to the recursion callling 
	}
	return ans;
}
int main()
{
  /*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int> *root = takeInputLevelWise();
	cout<<"num: "<<numNodes(root)<<endl;
	printTree(root);
	// TODO delete the tree.  
		delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 a predefined tree input.

/*     1
    /  |  \
  2   3    4
 /\  / \
 5 6 7 8
       |
	   9
*/