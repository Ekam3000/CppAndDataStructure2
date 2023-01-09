/*
Rahul Counting Trees
Send Feedback
You are given a Binary tree T and an integer K. Input binary Trees T is consisting of N (numbered from 1 to N) nodes rooted at node 1 and each node has a number written on it, where the number written on the ith node is A[i].
Now, Rahul needs to find the number of unordered triplets (i,j,k), such that node i is an ancestor of node j as well as node k, and A[i]+A[j]+A[k]>=K
A node x is considered an ancestor of another node y, if x is parent of y or x is an ancestor of parent of y.
Help Rahul for the same.
Input Format :
Line 1 : 2 space separated integers N and K. 
Line 2 : N space separated integers, where the ith integer denotes A[i].
Line 3 : N-1 space separated integers, where the ith integer represents the parent of node i+1.
Output Format :
Print the required answer on a single line.
Contraints :
1<= N <= 500
0<= A[i] <=10^9
Sample Input 1 :
5 6
1 2 3 4 5
1 2 2 1
Sample Output 1 :
7
Sample Input 2 :
20 63
66 1 20 77 66 71 5 17 12 49 51 14 8 41 54 45 54 77 26 17
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
Sample Output 2 :
252


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