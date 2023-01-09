/*
Earn maximum coins
Send Feedback
You are given N balloons indexed from 0 to N-1, with some number painted on each of them represented by an array 'A'. By bursting a balloon i, you will gain some coins. The number of coins gained is equal to A[i-1]* A[i] * A[i+1]. After the burst, balloons i-1 and i+1 becomes adjacent.
Find the maximum coin you can gain by bursting all the balloons wisely.
Note: At each boundary, i.e, A[-1] and A[N]=1
Input Format:
The first line of input contains the total number of balloons.
The second line of input contains the number painted on each each ballon from index 0 to N-1.
Output Format:
The only output line contains the maximum profit earned by bursting all the balloons.
Constraints:
0 ≤ N ≤ 500, 0 ≤A[i] ≤ 100
Sample Input:
5
1 2 3 4 5 
Sample Output:
110
Explanation:
First burst 4, coins=3 * 4 * 5=60

2nd burst 3, coins=2 * 3 * 5=30

3rd burst 2, coins=1 * 2 * 5=10

4th burst 1, coins=1 * 1 * 5=5

At last burst 5, coins=1 * 5 * 1=5

Coins gained=60+30+10+5+5=110
*/