#include<bits/stdc++.h>
using namespace std;
int min_cost(int R, int C)
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++) {
            // base case
            if(i==0 and j==0)
            {
                dp[i][j] = cost[0][0];
            }
            else if(i==0)
            {
                dp[i][j] = dp[0][j-1] + cost[0][j];
            }
            else if(j==0)
            {
                 dp[i][j] = dp[i-1][0] + cost[i][0];
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+ cost[i][j];
            }
        }
    }
    return dp[R-1][C-1];
}