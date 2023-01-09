#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define id long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

const int N = 100005, M = 22;
vector<int> gr[N];

void bfs(int src, int n, int & ans)
{
    vector<int> dis(n+1, INT_MAX);
    queue<int> Q;
    Q.push(src);
    dis[src] = 0;
    while(!Q.empty())
    {
        int cur = Q.front();    
        Q.pop();
        for(auto neigh : gr[cur])
        {
            if(dis[neigh]==INT_MAX)
            {
                // neighbour not visited
                dis[neigh]= dis[cur] +1;
                Q.push(neigh);
            }
            else if(dis[neigh]>= dis[cur])
            {
                ans = min(ans,dis[neigh] + dis[cur] +1);
            }
        }
    }
}
void solve()
{
    int i, j, n, m, ans;
    cin >> n >> m;
    for (i = 0; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    ans = n+1;
    cout<<ans<<'\n';
    for (i = 0; i <= n; i++)
    {
        bfs(i, n, ans);
    }
    if(ans ==n+1)
    {
        cout<<" no cycle \n";
    }
    else{
        cout<<" shortest cycle is of length "<<ans<<"\n";
    }
}
int main(int argc, char **argv)
{
}