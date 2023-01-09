// for an undirected graph
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
int tin[N], tout[N], timer ;

void eular_tour_1(int cur, int par)
{
    cout << cur << " ";
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            eular_tour_1(x, cur);
            cout << cur << " ";
        }
    }
    return;
}
void eular_tour_2(int cur, int par)
{
    cout << cur << " ";
    tin[cur]= timer++;
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            eular_tour_2(x, cur);
        }
    }
        tout[cur]= timer++;
    cout << cur << " ";
    return;
}
void eular_tour_3(int cur, int par)
{
    cout << cur << " ";
    tin[cur]= ++ timer;
    for (auto x : gr[cur])
    {
        if (x != par)
        {
            eular_tour_3(x, cur);
        }
    }
    tout[cur] = timer;
    return;
}

//whether x is ancestor of y or not
bool is_ancestor(int x, int y)
{
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}
void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    //eular_tour_1(1, 0);
   // eular_tour_2(1, 0);
   timer =1;
    eular_tour_3(1, 0);
    for(i=1; i<=n;i++)
    {
        cout<<i <<" "<< tin[i]<<" "<<tout[i]<<'\n';
    }
    cout<<'\n';
    if(is_ancestor(1,7))
    {
       cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
int32_t main()
{
solve();
}