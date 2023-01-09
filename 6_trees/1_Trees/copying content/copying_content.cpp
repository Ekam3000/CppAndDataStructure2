#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
	T data;
	vector<TreeNode<T> *> children;

	TreeNode(T data)
	{
		this->data = data;
	}
	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	}
}; 
//1.) this 
/*
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
*/
// 2.) or this
 TreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cin>>rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cin >> childData;
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
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
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]); // child
	}
	/*output is like this 
	1:2,3,
	2:
	3:
    */
}
void PrintingPreOrder(TreeNode<int> *root)
{
	if (root == NULL)
	{
	  	return;
	}        
	cout<<root->data<<" ";
	for (int i = 0; i < root->children.size(); i++)
	{
	  	preorder(root->children[i]);
	}

}
int main()
{
	TreeNode<int> *root = takeInputLevelWise();
	//TreeNode<int>* root = takeInput();
	//printTree(root);
	PrintingPreOrder(root);
		delete root;
}