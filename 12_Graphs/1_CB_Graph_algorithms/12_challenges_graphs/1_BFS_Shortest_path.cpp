/*
Problem Name: BFS - Shortest Path
Problem Difficulty: None
Problem Constraints: 
1 <= q <= 10
2 <= n <= 1000
1 <= m <= (n*(n-1))/2
1 <= u,s,v <= n


Problem Description:
Consider an undirected graph consisting of <strong>'n'</strong> nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 . We define node <strong>'s'</strong> to be the starting position for a BFS.

Given <strong>'q'</strong> queries in the form of a graph and some starting node, <strong>'s'</strong> , perform each query by calculating the shortest distance from starting node <strong>'s'</strong>  to all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if <strong>'s'</strong> is disconnected from a node, print <strong>-1</strong> as the distance to that node. 

Input Format: The first line contains an integer,q , denoting the number of queries. The subsequent lines describe each query in the following format:

1. Each line contains N and M, the  number of nodes and edges respectively.

2. The next m lines contains u and v means that there is edge between u and v .

2. The last line contains 's', the starting node.
Sample Input: 2
4 2
1 2
1 3
1
3 1
2 3
2
Output Format: You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s itself. 
Sample Output: 6 6 -1
-1 6
*/