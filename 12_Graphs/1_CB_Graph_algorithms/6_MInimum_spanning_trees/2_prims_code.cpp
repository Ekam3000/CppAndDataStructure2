#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // Adjacency list
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        // most important stuff
        // init a min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        
        // another array
        // visited array that denotes whether a node has been included in MST or Not
        bool * vis= new bool[V]{0};
        int ans =0;
        // beginn
        Q.push({0,0}); // weight , node
        while(!Q.empty())
        {
            // pick out the edge with min weight
            auto best = Q.top();
            Q.pop(); 

            int to = best.second;
            int weight = best.first;

            if(vis[to])
            {
                // discard the edge , and continue
                continue;
            }
            //otherwise take the current edge 
            ans += weight;
            vis[to] = 1;

            // add the new edges in the queue
            for(auto x:l[to])
            {
                if(vis[x.first]==0)
                {
                       Q.push({x.second, x.first});
                }
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

     cout<<g.prim_mst()<<endl;
}