/*Problem Name: Coin Change
Problem Difficulty: None
Problem Constraints: 1<=N<=250
1<=m<=50
1 <= Si <= 50
Problem Description:
Given a value N, if we want to make change for N cents,
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
In how many ways can we make the change? The order of coins doesn’t matter.


Input Format: First line of input contain two space separated integers N and M.
Second line of input contains M space separated integers - value of coins.
Sample Input: 10 4
2 5 3 6
Output Format: Output a single integer denoting the number of ways to make the given change using given coin denominations.
Sample Output: 5
*/

#include <iostream>

using namespace std;

long long int dp[1005];
long long int count( long long int S[], long long int m, long long int n )
{
    dp[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            dp[j] += dp[j-S[i]];
 
    return dp[n];
}

int main()
{
	long long int val[1005];
	//freopen("test.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int  N,M;
    scanf("%d%d",&N,&M);
    for(int i=0; i<M ;++i)
    	scanf("%lld",&val[i]);
    cout<<count(val,M,N);
    return 0;
}