/*Min and Max of Binary Tree
Send Feedback
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.
Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints two integers denoting the minimum and the maximum data values respectively. A single line will separate them both.
Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 14
Sample Input 2:
10 20 60 -1 -1 3 50 -1 -1 -1 -1 
Sample Output 2:
3 60
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
pair<int, int> MinMaxNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int, int> p;
		p.first = 999;
		p.second = -1;
		return p;
    }
    pair<int, int> p;
    p.first = root->data;
    p.second = root->data;
    pair<int, int> r = MinMaxNodes(root->left);
    p.first = min(p.first,r.first);
    p.second = max(p.second,r.second);
    pair<int, int> q= MinMaxNodes(root->right);
    p.first = min(p.first,q.first);
    p.second = max(p.second,q.second);
    return p;
}
int main() {
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	//printlevelwise(root);
    MinMaxNodes(root);
    cout<<MinMaxNodes(root).first<<" "<<MinMaxNodes(root).second<<endl;
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