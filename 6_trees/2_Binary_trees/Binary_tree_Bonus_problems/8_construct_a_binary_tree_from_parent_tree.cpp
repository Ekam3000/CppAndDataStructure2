/*Construct binary tree from parent array
Send Feedback
You are given an N-sized array that represents a binary tree such that array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root index is -1 as there is no parent of the root node. You have to construct a binary tree from the given parent array.
Note:
You have to return the root of the constructed tree. The Output will be the sorted level order traversal of the tree.
Input Format:
The first line of input contains the size of the parent array(N). The next line input contains the space-separated elements of the input parent array.
Output Format:
The Output will be the sorted level order traversal of the tree. Each level of the tree is printed in a new line and in a sorted manner.
Sample Input:
7
6 0 6 2 2 3 -1
Sample Output:
6 
0 2 
1 3 4 
5
Explanation
                        6
                       / \
                      0   2
                     /   / \
                    1   3   4
                       /
                      5
Value at index 6 is -1. So, 6 is the root of the tree.
6 is present at indexes 0 and 2. As 0 is smaller than 2 so, 0 is the left child and 2 is the right child of 6.
0 is present at index 1. As, 1 is the only child of 0 so it is inserted as the left child of 0.
2 is present at  indexes 3 and 4. As 3 is smaller than 4 so, 3 is the left child and 4 is the right child of 2.
5 is present at index 3. As, 5 is the only child of 3 so it is inserted as the left child of 3.
*/