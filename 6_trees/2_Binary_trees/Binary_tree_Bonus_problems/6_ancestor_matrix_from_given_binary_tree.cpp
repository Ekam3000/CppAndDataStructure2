/*Ancestor matrix from given binary tree
Send Feedback
You are given a binary tree in level wise order where all the values are from 0 to n-1. You have to construct an ancestor matrix of size n x n from the given binary tree.
Note: You have to write a function to print the ancestor matrix. The matrix given to you as the function argument is initialised with 0.
Ancestor matrix is defined as:
matrix[i][j] = 1 if i is ancestor of j
matrix[i][j] = 0, otherwise
Input format:
The first line of input contains the number of nodes in binary tree and the following line of input has elements in the level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format:
Ancestor matrix in n lines and n columns.
Sample Input:
5
0 1 2 3 4 -1 -1 -1 -1 -1 -1
Sample Output:
0 1 1 1 1
0 0 0 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Explanation:
                            0
                          /   \
                         1     2
                        / \
                       3   4
                       */