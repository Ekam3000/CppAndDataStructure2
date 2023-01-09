/*Morris preorder traversal
Send Feedback
Given a binary tree, print the Morris preorder traversal of the given tree.
Using Morris Traversal, we can traverse the tree without using stack and recursion.
Pre-order traversal is: Root LeftChild RightChild
Input format :
Elements in the level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Pre-order traversal, elements separated by space
Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output :
8 3 1 6 4 7 10 14 13
Explanation:
             8
           /   \
          3     10
         / \      \
         1   6     14
            / \    /
           4   7  13
           */