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

int nextGreaterInt(TreeNode<int>* root, int x )
{
    int ans;
    if(root==NULL)
    {
        return -1;
    }
    else if(root->data>x)
    {
        ans = root->data;
    }
    else
    {
        ans =-1;
    }
    for (int i = 0; i < root->children.size(); i++)
	{
        int temp=nextGreaterInt(root->children[i],x);
        if(temp>x and ans == -1)
        {
            ans =temp;
        }
        else if(ans > temp){
            ans =temp;
        }
        else{
            continue;
        }
    }
    return ans;
}
int main()
{
	TreeNode<int> *root = takeInputLevelWise();
    int x =10;
	cout<<nextGreaterInt(root, x);
		delete root;
}


/*
10 3 5 6 12 2 9 8 2 100 3 0 0 0 0 0 
*/