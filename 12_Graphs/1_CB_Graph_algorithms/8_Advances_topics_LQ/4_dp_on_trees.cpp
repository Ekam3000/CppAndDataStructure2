#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 100;

vector<int> gr[N];
int dp[N], vis[N];
void dfs(int cur, int par)
{
   dp[cur] = cur; //min value of a prticular node
    //dp[cur] = val[cur];
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
            dp[cur] = min(dp[cur], dp[x]);
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    // root is 1
    dfs(1, 0);
    for (int i = 0; i <= n; i++)
    {
        cout << i << " " << dp[i] << '\n';
    }
}