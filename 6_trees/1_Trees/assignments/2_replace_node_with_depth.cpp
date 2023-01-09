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
	~TreeNode()
	{
		for (int i = 0; i < children.size(); i++)
		{
			delete children[i];
		}
	}
};

TreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cin >> rootData;
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

void ReplaceNodeWithDepth(TreeNode<int> *root,int depth)
{
	if (root == NULL)
		return;
	root->data = depth;
	for (int i = 0; i < root->children.size(); i++)
	{
      
		ReplaceNodeWithDepth(root->children[i],depth+1);
		
	}
}
/*
void print(TreeNode<int> *root)
{
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		cout << front->data;
		pendingNodes.pop();
		for (int i = 0; i < front->children.size(); i++)
		{
			pendingNodes.push(front->children[i]);
		}
	}
}*/

void print(TreeNode<int> *root)
{
	queue<TreeNode<int> *> pendingNodes;
	cout << root->data << endl;
	pendingNodes.push(root);
	int n = 1;
	int count = 0;
	while (pendingNodes.size() != 0)
	{
		for (int i = 0; i < n; i++)
		{
			TreeNode<int> *front = pendingNodes.front();
			pendingNodes.pop();

			for (int i = 0; i < front->children.size(); i++)
			{
				pendingNodes.push(front->children[i]);
				count++;
			}
			for (int i = 0; i < front->children.size(); i++)
			{
				cout << front->children[i]->data << " ";
			}
		}
		cout<<endl;
		n =count;
		count=0;
	}
}
int main()
{
	TreeNode<int> *root = takeInputLevelWise();
	ReplaceNodeWithDepth(root,0);
	print(root);
	delete root;
}

/*     1
	/  |  \
  2    3    4
 /\   / \
 5 6  7 8
		|
		9
*/

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0