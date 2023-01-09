#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int dp[1001][1001];


int numWays(int Ro, int Col)
{
    // base case
    if(dp[0][0]==-1)
    {
        return 0;
    }
    // compute the no of ways for the first row
    for(int j=0;j<Col;j++)
    {
        if(dp[0][j]==-1)
        {
            break;
        }
        dp[0][j] =1;
    }
    // compute the no of ways for the first col
      for(int j=0;j<Col;j++)
    {
        if(dp[j][0]==-1)
        {
            break;
        }
        dp[j][0] =1;
    }

    //  Bottom Up approach for Rest of the Matrix 
    for(int i=1;i<Ro;i++)
    {
        for(int j=1;j<Col;j++)
        {
            // if cell is blocked leave it
            if(dp[i][j] != -1)
            {
                continue;
            }
            dp[i][j] = 0;
            if(dp[i][j-1] != -1)
            {
                dp[i][j] = dp[i][j-1]%MOD;
            }
            if(dp[i-1][j] != -1)
            {
                dp[i][j] =(dp[i][j] + dp[i-1][j])% MOD;
            }
        }
        // check for the final cells
        if(dp[Ro-1][Col -1] == -1)
        {
          return 0;
        }
        return dp[Ro-1][Col-1];
    }
    // print the entire DP tab

    for(int i=0;i<Ro;i++)
    {
        for(int j=0;j<Col;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
        return dp[Ro-1][Col-1];
}
int main()
{
    memset(dp,0,sizeof(dp));
    int N,M,P;
    cin>>M>>N>>P;
    for(int i=0;i<P;i++)
    {
        int X,Y;
        cin>>X>>Y;
        // mark all the blocked cells as -1
        dp[X-1][Y-1] =-1;
    }
    cout<<numWays(M,N)<<endl;
}