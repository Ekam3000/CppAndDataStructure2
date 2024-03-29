/*Problem Name: Dijkstra's Algorithm
Problem Difficulty: None
Problem Constraints: 1 <= N <= 3000
1 <= M <= (N*(N-1))/2
1 <= x,y <= N
1 <= r <= 10^5
Problem Description:
Given a graph consisting 'N' nodes (labeled 1 to N) where a specific given node 'S' represents the starting position and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node 'S') to all of the other nodes in the graph. 

If a node is unreachable, the distance is assumed as -1.

Input Format: The first line contains T, denoting the number of test cases.
First line of each test case has two integers N, M denoting the number of nodes in the graph and, denoting the number of edges in the graph.

The next M lines each consist of three space-separated integers x,y,r where x and y denote the two nodes between which the undirected edge exists, 'r' denotes the length of edge between these corresponding nodes.

The last line has an integer, 'S' denoting the starting position. 
Sample Input: 1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1


Output Format: For each of the T test cases, print a single line consisting N-1 space separated integers denoting the shortest distance of N-1 nodes other than from starting position S in increasing order of their labels.

For unreachable nodes, print -1.
Sample Output: 24 3 15

*/
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>

 
using namespace std;
 
const int N = 3000;
const int W = 1e5;
const int INF = 1e9;

vector<pair<int, int>> g[N];
int dist[N];
bool visited[N];
    
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        assert(2 <= n && n <= N);
        assert(1 <= m && m <= 1LL * n * (n - 1) / 2);
        
        for(int i = 0; i < n; ++i) g[i].clear();
        for(int i = 0; i < m; i++)
        {
            int v, u, w;
            scanf("%d %d %d", &v, &u, &w);
            assert(1 <= v && v <= n);
            assert(1 <= u && u <= n);
            assert(1 <= w && w <= W);
            --v; --u;
            g[v].push_back({u, w});
            g[u].push_back({v, w});
        }
        int s;
        scanf("%d", &s);
        --s;
        
        fill(dist, dist + n, INF);
        fill(visited, visited + n, 0);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, s});
        while(!q.empty())
        {
            int v = q.top().second;
            int d = q.top().first;
            q.pop();
            if(visited[v]) continue;
            visited[v] = 1;
            for(auto it: g[v])
            {
                int u = it.first;
                int w = it.second;
                if(dist[v] + w < dist[u])
                {
                    dist[u] = dist[v] + w;
                    q.push({dist[u], u});
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(i == s) continue;
            printf("%d ", (dist[i] != INF ? dist[i] : -1));
        }
        printf("\n");
    }
	return 0;
}
