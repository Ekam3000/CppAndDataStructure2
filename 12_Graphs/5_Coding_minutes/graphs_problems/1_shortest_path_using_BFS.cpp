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
    void addEdge(int x, int y, bool undir= true)
    {
        l[x].push_back(y);
        if(undir)
        l[y].push_back(x);
    }
    void bfs(int  source, int dest =-1)
    {
     bool* visited= new bool [V]{0};
     int *dist = new int [V]{0};
     int *parent = new int [V];
     for(int i=0; i<V; i++)
     {
        parent[i]=-1;
     }
     queue<int > q;
     q.push(source);
     visited[source]= true;
     parent[source]= source;
     dist[source] =0;
     while(!q.empty())
     {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr : l[node])
        {
            if(!visited[nbr])
            {
                q.push(nbr);
                // mark that nbr as visited
                parent[nbr] =node;
                dist[nbr] = dist[node] +1;
                visited[nbr] =true;
            }
        }
     }
     //print  shortest distance
    for(int i=0; i<V; i++)
    {
         cout<<"shortest distance to "<<i<<" is "<<dist[i]<<endl;
    }
    // print the path from a source to any dest
    if(dest !=-1)
    {
        int temp = dest;
        while(temp != source)
        {
            cout<<temp <<" -- ";
            temp = parent[temp];
        }
        cout<<source <<endl;
    }

    }
};
int main()
{
Graph g(7);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(3,5);
g.addEdge(5,6);
g.addEdge(4,5);
g.addEdge(0,4);
g.addEdge(3,4);
g.bfs(1);
}