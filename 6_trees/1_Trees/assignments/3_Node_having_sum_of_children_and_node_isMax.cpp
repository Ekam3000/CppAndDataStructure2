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
pair<int,int> MaxSumOfChildrenAndNode(TreeNode<int>* root)
{
    pair<int, int> ans;
    if(root == NULL )
    {
        pair<int, int> a;
        a.first = -1;
        a.second =-1;
        return a;
    }
    else
    {
    ans.first = root->data;
    ans.second = root->data;
    for(int i = 0; i < root->children.size(); i++)
    {
        ans.second += root->children[i]->data;
    }
    }
    
    for(int i = 0; i < root->children.size(); i++)
    {
     pair<int,int> data= MaxSumOfChildrenAndNode(root->children[i]);
      if(data.second> ans.second) 
      {
        ans = data;
      }
    }
    return ans;
    
    
}
int main()
{
	TreeNode<int> *root = takeInputLevelWise();
	cout<<MaxSumOfChildrenAndNode(root).first; 
	delete root;
}
// 10 3 2 3 4 2 100 200 1 5 1 8 0 0 0 0 