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
int Depth_of_binary_tree(BinaryTreeNode<int>* root)
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
	if(v1.size()<v.size())
	{
		return v;
	}
	else
	{
		return v1;
	}
}

int main() {
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printlevelwise(root);
	int depth =Depth_of_binary_tree(root);
   vector<int> v = LongestLeafToNodePath(root,depth,0);

	for(int i=0; i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	delete root;
}
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1 
