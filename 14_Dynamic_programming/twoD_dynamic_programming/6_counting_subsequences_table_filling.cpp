#include<bits/stdc++.h>
using namespace std;
// recursive code
int countSub(string a, string b, int m, int n)
{
    // base case
    if((m==-1 and n==-1 )or n==-1)
    {
        return 1;
    }
    if(m==-1)

    {
        return 0;
    }
    if(a[m]==b[n])
    {
        return countSub(a,b,m-1,n-1) + countSub(a,b,m-1,n);
    }
    return countSub(a,b,m-1,n);
}
// count subsequences buttom up 
int countBU(string a, string b)
{
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // fill the table in bottom up manner
    // first col as 1

    for(int i = 0; i <= m; i++)
    {
        dp[i][0]= 1;
    }
    //1,1 ......m,n
    for(int i = 1; i <=m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
            }
            else
            {
                dp[i][j]= dp[i-1][j];
            }
        }
    }

    return dp[m][n];   
}

int main()
{
    string a ="ABCECDG";
    string b="ABC";
    cout<<countSub(a,b,a.length()-1,b.length()-1)<<endl;
    cout<<countBU(a,b)<<endl;

}