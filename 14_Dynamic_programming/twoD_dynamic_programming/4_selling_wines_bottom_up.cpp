#include<bits/stdc++.h>
using namespace std;
 

 int wines(int dp[][10], int prices[], int L, int R, int y)
 {
   if(L> R)
   {
    return 0;
   }
   // need if a state is already
   if(dp[L][R] != 0)
   {
    return dp[L][R];
   }
   // rec case
   int pick_left = y*prices[L] + wines(dp,prices,L+1,R,y+1);
   int pick_right = y*prices[R] + wines(dp,prices,L,R-1,y+1);

   return dp[L][R] = max(pick_right,pick_left);
 }



 int wines_buttom_up(int prices[], int n)
 {

     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
     for(int i=n-1;i>=0;i--)
     {
        // bottom row to top row
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j] = n*prices[i];
            }
           else  if(i<j)
            {
                // dp(i.....j)
                int y= n-(j-i);
                int pick_left = prices[i]*y + dp[i+1][j];
                int pick_right = prices[j]*y + dp[i][j-1];

                dp[i][j] = max(pick_left,pick_right);
            }
        }
     }
       for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
 }

 int main()
 {
    int a[]={2,3,5,1,4};
    int n=5;
    int dp[10][10] ={0};
    cout<<wines(dp,a,0,n-1,1)<<endl;
      for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
  
    cout<<wines_buttom_up(a,n)<<endl;
 }