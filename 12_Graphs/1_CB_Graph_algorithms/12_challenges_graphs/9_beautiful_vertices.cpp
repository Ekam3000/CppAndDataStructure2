/*Problem Name: Beautiful Vertices
Problem Difficulty: None
Problem Constraints: 1 <= N <= 100000
0 <= M <= N-1
1 <= x,y <= N
Problem Description:
You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent.
A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.

Input Format: First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y. 
Sample Input: 4 3
1 2
2 3
2 4
Output Format: Print the number of beautiful vertices in the graph.
*/