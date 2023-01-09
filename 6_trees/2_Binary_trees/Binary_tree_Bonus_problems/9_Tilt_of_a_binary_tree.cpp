/*Tilt of a Binary tree
Send Feedback
You are given a binary tree and you have to return the tilt of the whole tree.
Tilt of the whole tree is the sum of all nodes' tilt and the tilt of a node is the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. The tilt of null nodes is 0.
Input Format:
The only input line contains nodes in the level order form (separated by space). If any node does not have left or right child, take -1 in its place.
Output format:
The only output line contains the tilt of the whole tree.
Sample Input:
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
Sample Output:
9
Explanation:
                    1
                   / \
                  2   3
                 / \   \
                4   5   6
Tilt of node 4=0
Tilt of node 5=0
Tilt of node 6=0
Tilt of node 2=|4-5|=1
Tilt of node 3=|0-6|=6
Tilt of node 1=|11-9|=2
Tilt of the whole tree=1+2+6=9
*/