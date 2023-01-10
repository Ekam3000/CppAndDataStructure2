#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{// a thing interesting obout the template is u will initialize the data type of template in the main function ,,and at rest other places in the code u will write T for the datatype
    map<T,list<T>> l;
    public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src)
    {// if the node is visited i.e it is present in the queue then it will be marked as visited 
     map<T,int> visited; // this will prevent the visited node for not to be inserted again in graph 
     queue<T> q;
     q.push(src);
     visited[src]= true;
     while(!q.empty())
     {
        T node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr : l[node])
        {
            if(!visited[nbr]) // becoz a node can be a neighbor of 2-3 vertices , so it is placed already in the queue by the first node .. then it will not to be allowed to push into queue by other vertex
            {
                q.push(nbr);
                // mark that nbr as visited
                visited[nbr] =true;
            }
        }
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
//0 1 3 2 4 5
// bfs is our iterative way of traversing the graph
// its like a level order traversal like we have done in trees 
/*
2---1
|   |
3---0
|
4---5
*/