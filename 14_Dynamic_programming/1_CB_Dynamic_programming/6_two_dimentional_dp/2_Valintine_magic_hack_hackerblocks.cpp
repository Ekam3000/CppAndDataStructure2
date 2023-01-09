#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000099ll
#define mod 1000000007
#define ll long long

ll n, m, a[5005], b[5005], dp[5005][5005];

// i is the index for boy, j is the index for girl

ll f(ll i, ll j)
{
    if (i == n)
    {
        // we have paired all the boys
        return 0;
    }
    if (j == m)
    {
        // wehave rejected lot of girls , and no girl is avbl for the boys
        return INF;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }

    int op1 = abs(a[i] - b[j]) + f(i + 1, j + 1); // by accepting the jth girl
    int op2 = f(i, j + 1);                        // by rejecting the jth girl
    return dp[i][j] = min(op1, op2);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    // top down DP
    ll ans = f(0,0);
    cout<<ans<<endl;
    return 0;
}