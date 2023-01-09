/*
Maximum Path Sum Between Two Leaves
Send Feedback
Given a binary tree of N nodes, find and return the maximum sum path between two leaves of the given tree.
Given binary tree contains positive values only.
Note: If there is only one leaf in the tree, then return 0 as answer.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Maximum sum path between two leaves
Constraints :
1 <= N <= 10^5
Sample Input :
10 9 4 3 1 5 8 -1 -1 -1 -1 -1 6 -1 -1 3 -1 -1 -1
Sample Output :
40

*/
#include<iostream>
#include<vector>
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

vector<int> LongestLeafToNodePath(BinaryTreeNode<int> * root, int depth , int currdepth)
{
	
	if(root==NULL)
	{
		vector<int> v;
		return v;
	}
    if(currdepth == depth)
	{
		vector<int> v;
		v.push_back(root->data);
		
		return v;
	}
    vector<int> v = LongestLeafToNodePath(root->left, depth, currdepth+1);
	if(v.size()>0 and currdepth <depth)
	{
		v.push_back(root->data);
	}
	vector<int> v1=LongestLeafToNodePath(root->right, depth, currdepth+1 );
	if(v1.size()>0 and currdepth <depth)
	{
		v1.push_back(root->data);
	}
	int sum =0, sum1=0;
	for(int i : v)
	{
     sum+=i;
	}
	for(int i : v1)
	{
     sum1+=i;
	}
	if(v.size()>v1.size())
	{
		return v;
	}
	else if(v.size()== v1.size())
	{
		if(sum> sum1)
		{
			return v;
		}
		else
		{
			return v1;
		}
	}
	else
	{
		return v1;
	}
}

void MaxPathSum(BinaryTreeNode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	int sum =0;
	int h1 = height(root->left);
	h1 =h1-1;
    vector<int> v =LongestLeafToNodePath(root->left,h1,0);
	for(int i : v)
	{
     sum+=i;
	}
   int h2 = height(root->right);
	h2= h2-1;
	vector<int> v1 =LongestLeafToNodePath(root->right,h2,0);
	for(int i : v1)
	{
		sum += i;
	}
	sum = sum + root->data;
	cout<<sum<<endl;
}

int main() {
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	MaxPathSum(root);
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