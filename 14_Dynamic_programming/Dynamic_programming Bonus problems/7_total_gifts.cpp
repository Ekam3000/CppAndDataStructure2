/*
Total Gifts
Send Feedback
A man is giving gifts to some kids. The kids are standing in a row on stairs, at different heights. Each kid should receive at least one gift. If two adjacent kids are at different heights, then the kid that is higher should receive one more gift than that is lower down. If two kids are at same height, then their gifts relative to each other doesn't matter. You are given number of kids and the heights of kids in order, then find the minimum number of gifts man has to bring to distribute between those kids.
Input Format:
The first line of input contains the number of kids.
The second line of input contains the heights of kids in order.
Output Format:
The only output line contains the minimum number of gifts that man should bring.
Constraints:
0 ≤ number of kids ≤ 500
0 ≤ heights ≤ 100
Sample Input:
6
2 5 4 7 3 2
Sample Output:
10
Explanation:
The gifts can be distributed among the kids in the following way, 1, 2, 1, 3, 2, 1. The second kid will receive more gifts than the first due to its height being higher. The fourth must receive more than the fifth, which in turn must receive more than the sixth. Thus the total becomes 10.
*/