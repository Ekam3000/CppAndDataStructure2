/*
Delivery boy
Send Feedback
A and B are two delivery boys on a pizza shop. The pizza shop received a total of N orders. The tip amount can be different when handled by a different delivery man. That is, if A takes ith order he gets a tip of Ai rupees, and if B takes ith order he gets a tip of Bi rupees.
One delivery boy can handle one order at a time. A can't handle more than X orders and B can't handle more than Y orders.
A and B have to distribute the orders among themselves such the total tip money is maximised. Find that maximum possible tip amount after delivering all the orders.
Input Format:
The first line of input contains 3 integers N, X and Y.
The second line of input contains tip amounts of A for N orders separated by space.
The last line of input contains tip amounts of B for N orders separated by space.
Output Format:
 The only line of output contains the maximum tip money they would receive.
Constraints:
1 ≤ N ≤ 10 5
1 ≤ X, Y ≤ N; X + Y ≥ N
1 ≤ Ai, Bi ≤ 104
Sample Input:
5 4 4 
9 7 6 5 3
5 6 7 8 9
Sample Output:
40
*/