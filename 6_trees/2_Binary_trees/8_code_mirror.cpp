/*Code : Mirror
Send Feedback
For a given Binary Tree of type integer, update it with its corresponding mirror image.
Example:
          1
        /   \
       2     3    <--- original BT
      / \   / \
     4  5   6  7

          1
        /   \
       3     2   <--- Mirrored BT
      / \   / \
     7   6 5   4

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the mirrored tree in a level-wise order.
Each level will be printed on a new line. Elements printed at each level will be separated by a single line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1
3 2
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5
6 10
3 2
9
*/

#include <iostream>
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
BinaryTreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;
  if (rootData == -1)
  {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter left child of " << front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    cout << "Enter right child of " << front->data << endl;
    int rightChildData;
    cin >> rightChildData;
    if (rightChildData != -1)
    {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
      front->right = child;
      pendingNodes.push(child);
    }
  }
  return root;
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

void mirrorTree(BinaryTreeNode<int>* root)
{
  if(root==NULL)
  {
    return;
  }
  BinaryTreeNode<int>* temp = root->left;
  root->left= root->right;
  root->right= temp;
  mirrorTree(root->left);
  mirrorTree(root->right);
}
int main()
{

  BinaryTreeNode<int> *root = takeInputLevelWise();
  mirrorTree(root);
  printlevelwise(root);
  delete root;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
/*
level order inputs-->
     1
   /   \
  2     3
 / \   / \
4  5  6   7
     / \
    8   9

*/
