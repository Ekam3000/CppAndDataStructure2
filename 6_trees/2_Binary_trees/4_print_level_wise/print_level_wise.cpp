/*Print Level Wise
Send Feedback
For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.
example --
 
        picture

For the above depicted Binary Tree, the level order travel will be printed as followed:

1:L:2,R:3
2:L:4:,R:-1
3:L:5:,R:6
4:L:-1:,R:7
5:L:-1:,R:-1    
6:L:-1:,R:-1
7:L:-1:,R:-1

Note: There is no space in between while printing the information for each node.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
Information of all the nodes in the Binary Tree will be printed on a different line where each node will follow a format of D:L:X,R:Y, without any spaces in between.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 Sample Output 2:
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1
*/
#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;
BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}
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

void printlevelwise(BinaryTreeNode<int> *root)
{
  queue<BinaryTreeNode<int> *> pendingNodes;
  cout << root->data << endl;
  pendingNodes.push(root);
  int n = 1;
  int count = 0;
  while (pendingNodes.size() != 0)
  {
    for (int i = 0; i < n; i++)
    {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
      if (front->left != NULL)
      {
        cout << front->left->data << " ";
        pendingNodes.push(front->left);
        count++;
      }
      if (front->right != NULL)
      {
        cout << front->right->data << " ";
        pendingNodes.push(front->right);
        count++;
      }
    }
    cout << endl;
    n = count;
    count = 0;
  }
}

int main() {
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printlevelwise(root);
	delete root;
}
/*
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
 
     1
   /   \
  2     3
 / \   / \
4  5  6   7
     / \
    8   9
 


Enter root data
1
Enter left child of 1
2
Enter right child of 1
3
Enter left child of 2
4
Enter right child of 2
5
Enter left child of 3
6
Enter right child of 3
7
Enter left child of 4
-1
Enter right child of 4
-1
Enter left child of 5
-1
Enter right child of 5
-1
Enter left child of 6
8
Enter right child of 6
9
Enter left child of 7
-1
Enter right child of 7
-1
Enter left child of 8
-1
Enter right child of 8
-1
Enter left child of 9
-1
Enter right child of 9
-1*/