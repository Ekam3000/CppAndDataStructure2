#include <bits/stdc++.h>
using namespace std;

// minimum steps to one
// n->n/3 , n/2 ,n-1
// top down
int minSteps(int n, int dp[])
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    // rec case
    // look up if n is already computed
    if(dp[n] != 0)
    {
        return dp[n];
    }
    // compute if dp[n] is not known (for first)
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if (n % 3 == 0)
    {
        op1 = minSteps(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = minSteps(n / 2, dp) + 1;
    }
    op3 = minSteps(n - 1, dp) + 1;
    int ans = min(min(op1, op2), op3);
    return dp[n]=ans;
}
// bottom up
int minStepsBU(int n)
{
    // bottom up approach
    int dp[100] ={0};
    dp[1] =0;
    for(int i=2;i<=n;i++)
    {
       int op1, op2, op3;
       op1 =op2 = op3 = INT_MAX;
       if(n%3==0) 
       {
        op1 =dp[i/3];
       }
       if(n%2==0) 
       {
        op2 =dp[i/2];
       }
       op3 = dp[i-1];
       dp[i] =min(min(op1, op2),op3) +1;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int dp[100] ={0};
   // cout<<minSteps(n,dp);
   cout<<minStepsBU(n)<<endl;
    return 0;
}