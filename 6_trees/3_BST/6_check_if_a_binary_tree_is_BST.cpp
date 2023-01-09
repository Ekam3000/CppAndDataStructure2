/*Code: Print Elements in Range
Send Feedback
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.
Output Format:
 The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements in increasing order.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10
*/
int maximum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MIN;
	}
	//return max(root->data, max(maximum(root->left), maximum(root->right)));
	if(root->right ) { maximum(root->right);
	}
	return root->data;
}
int minimum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MAX;
	}
	//return min(root->data, min(minimum(root->left), minimum(root->right)));
	if(root->left ) { maximum(root->left);
	}
	return root->data;
}
bool isBST(BinaryTreeNode<int>* root) 
{
	if (root == NULL) {
		return true;
	}
	int leftMax = maximum(root->left); // root shoulde be bigger than every element on the left subtree , for that we are finding the max element of the left subtree 
	int rightMin = minimum(root->right);
	bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
	return output;
} // time complexity is O(nh)



// in check_bst_2 we will return thre things minimum , maximum , IsBst .
// for that we will make either class of three variables or pair<pair<int, int>,int>
class IsBSTReturn {
	// public:
		bool isBST;
		int minimum;
		int maximum;
}; 
IsBSTReturn isBST2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	IsBSTReturn leftOutput = isBST2(root->left);
	IsBSTReturn rightOutput = isBST2(root->right);
	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
		leftOutput.isBST && rightOutput.isBST;
	IsBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
	return output;
} // time complexity is O(n) , hum har node par jaa kar ek constant work kar rahe hai 



// BST 2 is our bottom to top approach , like left subtree and right subtree pehle apna ans root ko pakda kar dete hai 

// BST 3 is our top to bottom approach 
// root par constraint hai ki vaha elements INT_MIN to INT_MAX takk kuch bhi place ho sakta 
// root->left par constraint hai ki vaha elements INT_MIN to root->left -1 takk ki range me element ho sakta
// root->right par constraint hai ki vaha elements root->data to INT_MAX takk ki range me element ho sakta
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) { // default parameters 
	if (root == NULL) {
		return true;
	}
	if (root->data < min || root->data > max) {
		return false;
	}
	bool isLeftOk = isBST3(root->left, min, root->data - 1);
	bool isRightOk = isBST3(root->right, root->data, max);
	return isLeftOk && isRightOk;
}