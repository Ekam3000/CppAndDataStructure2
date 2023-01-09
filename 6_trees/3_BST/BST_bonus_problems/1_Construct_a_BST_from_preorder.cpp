/*
Construct a BST from preorder
Send Feedback
You are given preorder traversal of a Binary Search Tree, you have to construct a BST from this preorder traversal.
Input Format:
The first line of input contains the number of nodes present in the BST. The following line of input contains the preorder traversal of BST.
Output Format:
The output contains the constructed tree where each level is printed in a new line.
Constraints:
1<=Numberof nodes<=100
Sample Input:
6
20 10 2 14 80 100
Sample Output:
20
10 80
2 14 100
*/
#include<iostream>
#include<climits>
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
// 1st approach -> O(n^2)
/*
BinaryTreeNode<int > *construct_BST (BinaryTreeNode<int> * &root, int ele) {
        if(!root)
             return root = new BinaryTreeNode<int> (ele);
        if(root->data > ele)
             root->left= construct_BST (root->left, ele);
         else
             root->right =construct_BST(root->right, ele);
         return root;
}

 BinaryTreeNode<int> * buildBST (vector<int>& pre) {
         BinaryTreeNode<int> *root =NULL;
         for (auto x : pre)
             construct_BST(root, x);
         return root;

 }
 */
// 2nd approach O(n) -. we are traversing each node atmost 3 times 
/*
int construct_BST(vector<int> v, int n , int pos,BinaryTreeNode<int> * curr, int min= INT_MIN, int max= INT_MAX)
{
if(pos ==n || v[pos] < min || v[pos] > max)
{
    return pos;
}
if(v[pos]<curr->data)
{
    BinaryTreeNode<int> * leftchild = new BinaryTreeNode<int>(v[pos]);
    curr->left = leftchild;
    pos = construct_BST(v,n,pos+1,curr->left,min,curr->data -1);  
}//20 10 2 14 80 100 -suppose for 10 .it is the left child of 20 and its range is INT_MIN to 19.
// for 2 its range is INT_MIN to 9
// after inserting elements in the left subtree we will aagin look for pos maybe it is equal to n , so no need to go for right subtree
if(pos ==n || v[pos] < min || v[pos] > max)
{
    return pos;
}
    BinaryTreeNode<int> * rightchild = new BinaryTreeNode<int>(v[pos]);
    curr->right = rightchild;
    pos = construct_BST(v,n,pos+1,curr->right,curr->data, max);
    return pos;
// 14 will be right child of 10 , uski range rahe hi . 10 to 19
}
BinaryTreeNode<int>* buildBST(vector<int> v)
{
    int n = v.size();
    if(n==0)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(v[0]);
    if(n==1)
    {
        return root;
    }
    construct_BST(v,n,1,root);
    return root;
}*/
// approach 3 
// given preoder ko sort karke hum inorder bna sakte .. then from inorder and pre order we can construct BST like binaary tree

// approach 4 .. jaise hum preordr dekh kar BSt wali line ka ans  likhte hai na.. vaise hi ab code me ek ek element ko dekh kar bst construct karna .. 
// we need only upper bound in this case which is initiallly infinityin this case. 
// and if we are calling left then root->data becomes the uppar bound which is its boundary
// if we are calling the right child   then prev node (the parent of node(which is calling the right child) )
//O(n) 
BinaryTreeNode<int>* build(vector<int> & A, int &i, int bound)
{
    if(i==A.size()|| A[i]>=bound) return NULL;
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(A[i++]);
    root->left= build(A,i,root->data);
    root->right= build(A,i,bound);
    return root; 
}

BinaryTreeNode<int>* buildBST(vector<int> & A)
{
    int i=0;
    return build(A,i,INT_MAX);
}

int main()
{
    
   vector<int> v = {20, 10, 2 ,14,80, 100};
	BinaryTreeNode<int>* root = buildBST( v);
	printlevelwise(root);
    return 0;
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1 -> a bst
//20 10 2 14 80 100 -> a preorder 