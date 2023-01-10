// optimisation
// 1.  Path Compression Optimisation in DSU (find Fn)
// 2. Union by Rank (Union Fn)

#include <bits/stdc++.h>
using namespace std;
// cycle detection in a undirected graph using DSU
class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }
    int addEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }
    // Find
    // path compression is going to reduce the path length from child to parent eg 7->5 , 5->3 , 3->2 , 2->1 .. then we can directly say 7 ka parent 1
    int findSet(int i, int parent[])
    {
        // base case
        if (parent[i] == -1)
        {
            return i;
        }
        // this is the change we have done
        // path compression optimisation
        return parent[i] = findSet(parent[i], parent); // here all 2,3,5,7 parent becomes 1 
    }
    // union
    void union_set(int x, int y, int parent[])
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2)
        {
            parent[s1] = s2;
        }
    }
    bool contains_cycle()
    {
        // DSU logic to check if graph contains cycle or not
        int *parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }
        // iterate over the edge list
        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2)
            {
                union_set(s1, s2, parent);
            }
            else
            {
                cout << "same parents " << s1 << " and " << s2 << endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    cout << g.contains_cycle() << endl;
}

