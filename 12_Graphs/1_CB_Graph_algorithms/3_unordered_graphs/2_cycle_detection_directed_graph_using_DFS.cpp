#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    // array  of list
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y, bool directed = true) // so by default we are creating a undirected graph
    {
        l[x].push_back(y);

        if (!directed)
        {
            l[y].push_back(x);
        }
    }
    bool cycle_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node])
        {
            // two cases
            if (!visited[nbr])
            {
                // go and recursively visit the car
                bool cycle_mila = cycle_helper(nbr, visited, node);
                if (cycle_mila)
                    return true;
            }
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle()
    {
        // check for cycle in directed graph
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        return cycle_helper(0, visited, -1);
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    if (g.contains_cycle())
    {
        cout << "yes undirected graph conatins cycle" << endl;
    }
    else
        cout << "no, undirected graph not conatins cycle" << endl;
}
//cyclic graph -> if there is more than one way to visit any node ->true for an undirected graph 
// one thing we have to check that the node which we are going to visit should not be the parent of the node which is visiting it. 
/*
    1
   / \
  2   3
  |   |
  4---5
*/