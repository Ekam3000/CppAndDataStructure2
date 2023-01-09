/*Code : PostOrder Traversal
Send Feedback
Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 
Sample Output 1:
400 50 20 30 40 10
*/
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
// pehle children ki print hone ki turn then root ki print hone ki turn 
void postorder(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	for (int i = 0; i < root->children.size(); i++) {
		postorder(root->children[i]);
	}
	cout << root->data << " ";
} //5 6 2 7 9 8 3 4 1

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
	
	TreeNode<int>* root = takeInputLevelWise();
	postorder(root);
	// TODO delete the tree
	delete root;
	
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
 /*    1
    /  |  \
  2   3    4
 /\  / \
 5 6 7 8
       |
	   9
*/