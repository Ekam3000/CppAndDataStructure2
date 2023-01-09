/*Clone a binary tree
Send Feedback
You are given a binary tree with random pointers. A random pointer of a node points to any random node of the binary tree and it can even point to NULL. You have to clone this binary tree and return the root of the cloned binary tree.
Input Format:
The first line contains an integer N denoting the no of edges of the tree and then in the next line are N space-separated queries. The query on the tree are of three types
a) a b L  (Represents that b is the left child of a)
b) a b R (Represents that b is the right child of a)
c) a b X (Represents a random pointer from node a to node b)  
Output Format:
Your function should return the root of the cloned tree. The output will be 1 if the tree is successfully cloned.
Constraints:
0 <=Number of nodes<= 100
1 <=Data of a node<= 1000
Sample Input:
6
6 3 L 6 8 R 3 1 L 3 5 R 1 3 X 5 6 X
Sample Output:
1
*/