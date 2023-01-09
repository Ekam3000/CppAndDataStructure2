/*
BST Dead End
Send Feedback
You are given a Binary Search Tree. You have to check whether this tree contains a dead-end or not. The dead-end is a leaf node, after which we are not able to insert any node. That is, a dead end is said to exist in a BST, if there is a leaf node to which a new child node cannot be added without violating the properties of a BST.
Input Format:
The first line of input contains the number of nodes(N) to be inserted in the BST. The following line of input contains N space-separated elements to be inserted in the BST.
Output Format:
 The only output line contains "yes" if the dead-end is present in the BST otherwise "no" is printed.
Constraints:
1<=Numberof nodes<=1000
Sample Input:
6
8 7 10 9 13 2
Sample Output:
 yes
Explanation:
The BST is:
                         8
                        / \
                       7   10
                      /    / \
                     2    9  13

We can't insert any element at node 9.  Hence, 9 is a dead-end.
*/
/*
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
bool deadend(BinaryTreeNode<int> *root, int max = INT_MAX, int min = INT_MIN)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->left == NULL and root->right == NULL)
        {
         if(max-min==2 and root->data == min+1 ) // bcoz then root-> left will have value b/w (min,root->data) and no integer can be placed b/w (min,root->data) . similar for root->right
         {
            return true;
         }
        }
        if( deadend(root->left, root->data, min))
        {
            return true;
        }
        else if( deadend(root->right, max, root->data))
        {
           return true; 
        }
        return false;
    }
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    deadend(root);
}
//8 7 10 9 13 2 -> dead end -> 8 7 10 2 -1 9 13 -1 -1 -1 -1 -1 -1
//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1 -> a bst , not having dead end
*/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    // insert function returns a class object , becoz if root is NULL then we are creating a root node hence returning it
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insert(int data)
    {
        //	insert function returns a class object , becoz if root is NULL then we are creating a root node hence returning it and catches by this->root
        this->root = insert(data, this->root);
    }

private:
    bool deadend(BinaryTreeNode<int> *root, int max = INT_MAX, int min = INT_MIN)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->left == NULL and root->right == NULL)
        {
         if(max-min==2 and root->data == min+1 ) // bcoz then root-> left will have value b/w (min,root->data) and no integer can be placed b/w (min,root->data) . similar for root->right
         {
            return true;
         }
        }
        if( deadend(root->left, root->data, min))
        {
            return true;
        }
        else if( deadend(root->right, max, root->data))
        {
           return true; 
        }
        return false;
    }
        void printTree(BinaryTreeNode<int> *root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL)
		{
			cout << "L" << root->left->data;
		}
		if (root->right != NULL)
		{
			cout << "R" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);
	}
    public:
        bool deadend()
        {
            return deadend(this->root);
        }
    void printTree()
	{
		printTree(root);
	}
    };
    int main()
    {
        BST b;
        b.insert(8);
        b.insert(7);
        b.insert(10);
        b.insert(9);
        b.insert(13);
        b.insert(2);
        b.printTree();
        cout << b.deadend();
    }
    // 8 7 10 9 13 2 -> dead end