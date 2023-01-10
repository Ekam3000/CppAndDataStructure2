#include <bits/stdc++.h>
using namespace std;
// one node can have two - three dependencies nodes. but two maintain acyclic properties for that graph ..only one dependency can have its other dependencies , rest other should be independent nodes
/*
---1 -> 2<-- 4
        | 3 to 2
        3
        
        2 has 1,4,3 as its dependencies but 3 and 4 are independent and 1 is dependent 
*/
// iss question me hum parent wala concept nahi laye .
// stack name ki ek new chij aaye which will maintain the current path 
// when a node is visited mark it an visited and marks its presence in the stack 
//

/*
          A
A to C   / \ A to B
        C-->B
same concept of undirected graph wont be apply here(i.e if we visit a edge twice than its an undirected graph)

as in above graph we are visiting B twice , but its not a cyclic graph.
*/

// cycle sirf current path wale nodes ko hi lekar bn sakte.. jo nodes stack me present hai .
// back edge concept ->
// if a graph has a back edge .. then we say the node contains a cycle.
// back edge is an edge from node to a ancestor of that node in the same path  
class Graph
{
    list<int> *l;
    int V;
    public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y, bool directed = true)
    {
        // directed graph
        l[x].push_back(y);
        if (!directed)
        {
            l[y].push_back(x);
        }
    }

    bool cycle_helper(int node, bool *visited, bool *stack)
    {
        visited[node] = true;
        stack[node] = true;
        // stack name ki ek new chij aaye which will maintain the current path 
        for (int nbr : l[node])
        {
            // two cases
            if (stack[nbr] == true) // to chech node is present in the path or not 
            {
                return true;
            }
            else if (visited[nbr] == false)
            {
                bool cycle_mila = cycle_helper(nbr, visited, stack);
                if (cycle_mila)
                {
                    return true;
                }
            }
        }
        stack[node] = false; // once all neighbors of the node are visited , then mark its absence in the stack.. bcoz this node will not be present in our current path.
        return false;
    }
    bool contains_cycle()
    {
        // check for cycle in directed graph
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = stack[i] = false;
        }
        return cycle_helper(0, visited, stack);
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2); // back edge
    if(g.contains_cycle())
    {
        cout << "yes contains cycle" << endl;
    }
    else
    {
        cout << "no doesn't contains cycle" << endl;
    }
    return 0;
}