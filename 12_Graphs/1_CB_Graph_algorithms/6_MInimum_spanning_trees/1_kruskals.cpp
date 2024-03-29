#include <bits/stdc++.h>
using namespace std;
// dsu data structure
// path compression + union by rank
class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        // parent = -1 rank =1
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    // find function
    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        // otherwise
        return parent[i] = find(parent[i]);
    }
    // unite(union)
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            // union by rank
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
    int kruskal_mst()
    {
        // main logic = easy
        // 1. sort all the edges based upon weight
        sort(edgelist.begin(), edgelist.end());

        // init a DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // take that edge in mst if it doesn't form a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main()
{
     Graph g(4);
     g.addEdge(0,1,1);
     g.addEdge(1,3,3);
     g.addEdge(3,2,4);
     g.addEdge(2,0,2);
     g.addEdge(0,3,2);
     g.addEdge(1,2,2);

     cout<<g.kruskal_mst()<<endl;
}
/*
    1---
   1| 2 |2
    2---3
   2|   |3
    4---
    there is also an edge from 1 to 4 -> its weight is 2

    edge from 2 to 3 has weight 2
*/

//weighted undirected graphs
//spanning tree : connects all the vertices of the graph with each other
// if there are V vertices then we have V-1 edges that states the entire graph forms a single component without forming a cycle
// single connected component
// so spanning tree is the subset of edges