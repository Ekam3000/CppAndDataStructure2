/*

Count ways
Send Feedback
There exists a special graph which has directed M edges and N nodes and graph contains no cycles. Count the number of ways to reach different nodes from S. A way is called different from others if the destination node or used edges differ. As the ways can be large, print the ways modulo 1000000007.
Include source node as destination also.
Input Format:
Line 1 : Two Integers N and M
Next M lines : Two integers x, y which denotes an edge from x to y
(M+1)st line : S, source
Output Format:
Count of ways
Constraints :
1 <= S, N <= 100005
1 <= M <= 200005
1 <= x , y <= N
Sample Input :
4 3
1 2
2 3
3 4
2
Sample Output :
3
Sample Output Explanation :
From node 2 we can reach - 2, 3 and 4.
*/
