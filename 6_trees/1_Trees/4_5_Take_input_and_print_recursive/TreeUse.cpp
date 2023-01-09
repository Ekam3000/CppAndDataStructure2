#include <iostream>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* takeInput() 
{
	int rootData;
	cout <<"Enter data"<< endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin>>n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}
void printTree(TreeNode<int>* root) {
	if (root == NULL) {  
		return;  // this is an edge case( a condition) not an base case 
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ","; // root ke child print ho rahe hai
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]); // child
	}  
	// isme print karne ka style same hai as of 2_Take input levelwise.
   /*output is like this if main  function me line 39 to 43 input data hai.
	1:2,3,
	2:
	3:
	*/
}
int main() {
  /*TreeNode<int>* root = new     TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInput();
	printTree(root);
	// TODO delete the tree
		delete root;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 a predefined tree input.
/* 
      1
   /  | \
  2   3  4
 /\  / \
 5 6 7 8
       |
	   9
*/
