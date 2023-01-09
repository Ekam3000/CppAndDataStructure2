// dfs method
#include<bits/stdc++.h>
using namespace std;
class Graph
{
      int V;
    // array  of list
    list<int> *l;
    public:
    Graph(int v)
    {
        V=v;
        l = new list<int> [V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool dfs(int node, vector<bool> & visited, int parent)
    {
    // mark that node visited
    visited[node] = true;
    for(auto nbr : l[node])
    {
        if(!visited[nbr])
        {
            bool nbrFoundACycle = dfs(nbr, visited, node);
            if(nbrFoundACycle)  
            {
                 return true; 
            }
        }
        //nbr is visited and its not the parent of current node in the current dfs call
        else if(nbr != parent)
        {
            return true;
        }
    }
    return false;
    }
    bool contains_cycle()
    {
     // graph is single component
     vector<bool> visited (V,false);
     return dfs(0,visited, -1);
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    cout<<g.contains_cycle()<<endl;
}