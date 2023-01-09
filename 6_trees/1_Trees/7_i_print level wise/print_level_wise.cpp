/*Print Level Wise
Send Feedback
Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the elements of the tree in level wise order, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:
*/
#include <iostream>
#include <queue>
#include <vector>
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
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front(); // ek dusra pointer queue ke front pointer ko point kar raha hai ab
		pendingNodes.pop();							 // front node ko bahar nikala queue se
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			// TreeNode<int>* child(childData); // we want is memory to be survived, loop khatam hone ke baad ye memory deallocate ho jaye gi , but we want ye naa ho.
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child); // fornt ko child node se connect kar diya
			pendingNodes.push(child);		  // child node ko quque ke push out kar diya.
		}
	}
	return root;
}
void printTree(TreeNode<int> *root)
{
	if (root == NULL)
	{
		return; // this is an edge case( a condition) not an base case
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++)
	{
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++)
	{
		printTree(root->children[i]); // child
	}
	/*output is like this
	1:2,3,
	2:
	3:
	*/
}

void printlevelwise(TreeNode<int> *root)
{
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		cout << front->data<<":";
		pendingNodes.pop();
		for (int i = 0; i < front->children.size(); i++)
		{
			cout<<front->children[i]->data<<" ";
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
}


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
	printlevelwise(root);
	delete root;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 a predefined tree input.

/*    1
    /  |  \
  2   3    4
 /\  / \
 5 6 7 8
       |
	   9
*/