#include <bits/stdc++.h>
using namespace std;
// cycle detection in a undirected graph using DSU
class Graph
{
    int V;
    list<pair<int, int>> l; // so we making edgelist

public:
    Graph(int V)
    {
        this->V = V;
    }
    int addEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }

    // Find -> takes O(N) time complexity
    int findSet(int i, int parent[])
    {
        // base case
        if (parent[i] == -1)
        {
            return i;
        }
        return findSet(parent[i], parent);
    }


    // union
    void union_set(int x, int y, int parent[])
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2)
        {
            parent[s1] = s2; // here parent of 0 becomes 1 , so 0 and 1 are combined 
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
            int i = edge.first; // at first it is 0
            int j = edge.second; // at first it is 1
            int s1 = findSet(i, parent); // parent of 0 is 0
            int s2 = findSet(j, parent); // parent of 1 is 1 

            if (s1 != s2) // the parent are diff 
            {
                union_set(s1, s2, parent); // so combine 0 and 1 
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
// disjoint sets means non operlapping no common element
// disjoint sets supports two operations union and find
// find function will tell us in which set a particular element is present
// union -> merging two sets

// union (1,2) -> we will first see the parent of 1 by find(1) function then we will see the parent of 2 by find(2) function.. if the parent are same then the graph is cyclic.

// if the parent are different then then we set the parent of 2 as 1.. i.e merging them 