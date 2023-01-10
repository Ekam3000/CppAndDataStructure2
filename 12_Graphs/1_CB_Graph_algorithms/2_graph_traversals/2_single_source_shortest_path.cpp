#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    //  shortest path between source and destination
    // source and dest node will be provided to us
    // distance travelled by the level order traversal is the shortest provided that edges are unweighted
    
    map<T,list<T>> l;
    public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    // since we say a node is neighbor of maybe 2-3 nodes/vertices . the very time time a vertex will discovered that node,that path will be included in the shortest path

    // (for the first time a vertex sets the distance of the node to particular distance , that distance of node will not be changed if discovered by another vertex
    void bfs(T src)
    {
     map<T,int> dist;
     queue<T> q;
     // all other nodes will have int_max other than source
     for(auto node_pair: l )
     {
        T node =node_pair.first;
        dist[node] =INT_MAX;
     }
     q.push(src);
     dist[src]= 0;
     while(!q.empty())
     {
        T node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr : l[node])
        {  
        
            if(dist[nbr]==INT_MAX) // means the node is visited for the first time . for this ques , this is the condition for checking the the node is visited or not 
            //for this ques , this is the condition for checking the the node is visited or not
            {
                q.push(nbr);
                // mark that nbr as visited
                dist[nbr] =dist[node]+1;
            }
        }
     } 
     // print the dist to every node
     for(auto node_pair :l)
     {
        T node = node_pair.first;
        int d = dist[node];
        cout<<"Node "<<node<<" Dist from scr "<<d<<endl;
     }
    }
};
int main()
{
Graph<int> g;
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,5);
g.addEdge(3,0);
g.bfs(0);
}
/*
2---1
|   |
3---0
|
4---5
*/