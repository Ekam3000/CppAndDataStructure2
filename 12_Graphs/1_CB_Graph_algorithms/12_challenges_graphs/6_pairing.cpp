/*Problem Name: Pairing
Problem Difficulty: 
Problem Constraints: 1 <= N <= 100000
1 <= M <= 100000
0 <= X,Y <= N-1
Problem Description:
There are **N** cities numbered from ***0 to N-1***. You have to choose 2 cities such that there is no path from first city to second city .<br>
You are given information in the form of M pairs (X,Y) **i.e** there is an undirected road between city X and city Y.<br>
*Find out the number of ways in which cities can be chosen.*

Input Format: The first line contains two integers, N and M separated by a single space.
M lines follow.
Each line contains integers separated by a single space X and Y denoting road between X and Y.



Sample Input: 5 3
0 1
2 3
0 4
Output Format: An integer that denotes the number of permissible ways to choose a pair of cities.
Sample Output: 6



*/
/*input
10 7
0 2
1 8
1 4
2 8
2 6
3 5
6 9
*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define pii pair<long long,long long>
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define PI 3.14159265
#define ll int
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define INF 1000000009
#define mod 1000000007
vector <ll> graph[100045];
ll prefixsum[200005];
bool vis[200005];
ll temp;
vector <ll> cnt;
void dfs(ll u)
{
	//cout<<u<<endl;
	if(vis[u])
		return;
	vis[u] = true;
	ll sz = graph[u].size();
	F(i,0,sz-1)
	{
		ll v = graph[u][i];
		if(!vis[v])
		{
			temp++;
			dfs(v);
		}
	}
	return;
}
int main() 
{
	std::ios::sync_with_stdio(false);
	ll n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	long long ans = 1;
	memset(vis,false,sizeof(vis));
	F(i,0,n-1)
	{
		temp = 1;
		if(!vis[i])
		{
			dfs(i);
			cnt.pb(temp);
		}
	}
	ll sz = cnt.size();
	ans = 0;
	prefixsum[0] = cnt[0];
	F(i,1,sz-1)
	{
		prefixsum[i] = prefixsum[i-1] + cnt[i];
	}
	F(i,0,sz-1)
	{
		ans = ans + (prefixsum[sz-1]-prefixsum[i])*cnt[i];
	}
	printf("%lld\n",ans);
	return 0;
}