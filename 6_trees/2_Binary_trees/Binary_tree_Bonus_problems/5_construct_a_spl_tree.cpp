/*Construct a special tree
Send Feedback
You are given an array(preor) representing preorder traversal of a special binary tree where each node of this binary tree has either 0 or 2 children. One more array(preorLN) is given to you to represent if the current node is the leaf node or not with values "L" or "N" respectively. You have to write a function to construct this special tree and return the root of this tree.
Note: No need to print the tree. The printing of this special tree is already handled.
Input Format:
The first line of input contains the number of nodes present in the tree. The following line of input contains space-separated elements of the array preor. And the last line of input contains space-separated elements of the array preorLN.
Output Format:
The output contains the constructed special tree printed in the level-wise order. For printing a node with data N, you need to follow the exact format -
N:L:x, R:y
where N is data of any node present in the binary tree. x and y are the values of the left and right child of node N. Print -1. if any child is null.
Sample Input:
5
10 30 20 5 15
N N L L L
Sample Output:
10:L:30,R:15
30:L:20,R:5
15:L:-1,R:-1
Explanation:
The input tree given is:
       10
      /  \
     30   15
    /  \
  20    5
  */