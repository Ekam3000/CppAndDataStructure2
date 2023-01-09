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
pair<int,int> SecondLargestElement(TreeNode<int>* root)
{
	if(root==NULL)
	{
        pair<int, int> a;
        a.first = -1;
        a.second =-1;
        return a;
	}
	pair<int,int> ans;
	ans.first =root->data;
	ans.second =-1;
    for(int i = 0; i < root->children.size(); i++)
    {
        pair<int,int> data = SecondLargestElement(root->children[i]);
		    if(ans.first > data.second and data.first >ans.first)
			{
				ans.second=ans.first;
				ans.first=data.first;
			}
			else if(ans.first < data.second and data.first >ans.first)
			{
				ans.second=data.second;
				ans.first=data.first;
			}
            else if(data.first<ans.first and ans.second<data.first ) 
			{
				ans.second = data.first;
			}
    }
	return ans;
}
int main()
{
	TreeNode<int> *root = takeInputLevelWise();
	cout<<SecondLargestElement(root).second; 
	delete root;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0