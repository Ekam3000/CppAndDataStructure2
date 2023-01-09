/*Serialize and Deserialize
Send Feedback
You are given a binary tree and you have to serialize and deserialize the given binary tree. Serialization is to store the tree in an array so that it can be restored later while deserialization reading tree back from that array.
The structure of the tree must be maintained while serializing or deserializing the binary tree. You have to complete the function serialization and deserialization.
Input Format:
The first line contains an integer N denoting the no of edges of the tree and then in the next line are N space-separated queries. The query on the tree are of two types:
a) a b L  (Represents that b is the left child of a)
b) a b R (Represents that b is the right child of a)
Output Format:
The output will be the inorder traversal of the returned tree after deserialization.
Constraints:
0<= Number of nodes<= 100
1 <= Data of a node<= 100
Sample Input:
4
8 100 L 8 120 R 100 140 L 100 170 R
Sample Output:
140 100 170 8 120
*/