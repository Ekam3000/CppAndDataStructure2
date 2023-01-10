#include<bits/stdc++.h>
using namespace std;

template< typename T>
class Graph
{
    map<T,list<T>> l;
    public:
     void addEdge(T x, T y)
    {
        l[x].push_back(y);
        //l[y].push_back(x);
    }
   void dfs_helper(T src, map<T,bool> & visited, list<T> & ordering)
   {
    // Recursive function that will traverse the graph
   
    visited[src]=true;
    // go to all nbr of that node that is not visited
    for(T nbr :l[src])
    {
        if(!visited[nbr])
        {
            dfs_helper(nbr, visited,ordering);
        }
    }
    ordering.push_front(src); // push front ke wajah se linear ordering me elements dale ge
    return;
   }
    void dfs()
    {
        map<T,bool> visited;
        list<T> ordering;
        // mark all the nodes as not visited in the beginning
        for(auto p: l) // we have initialited maps as our container for storing the vertices that's why we are traversing  each element like this ..
        // in other cases we have initalized list as our container for storing the elemnts , in that case we will pass the vertex 'V' (the number of vertices) from main function 
        // and will used for loop  for (int i = 0; i < V; i++) for traversing  each vertex and not like for(auto p: l)
    
        {
            T node = p.first;
            visited[node]=false; 
        }
        // call the helper function
        for(auto p : l)
        { // make dfs call from every node , so that if any independent node is there should also be covered 
         T node = p.first;
         if(!visited[node])
         {
          dfs_helper(node, visited,ordering);
         }
        }
        for(auto node : ordering)
        {
            cout<<node<<endl;
        }
    }
};
int main()
{
Graph<string> g;
g.addEdge("python", "Datapreprocessing");
g.addEdge("python","Pytorch");
g.addEdge("python","ML");
g.addEdge("Datapreprocessing","ML");
g.addEdge("Pytorch","DL");
g.addEdge("ML","DL");
g.addEdge("DL","FaceRecogn");
g.addEdge("Dataset","FaceRecogn");
g.dfs();
}
// topological sorting is not performed for cyclic graphs

// for directed acyclic graphs the topological sort is possible
/*
          A
A to C   / \ A to B
        C-->B
*/

// we have to output linear ordering of the graph .. kis order me hame track karna 
// starting with vertex with doesnot have any dependency
// we have go to a vertex only if all its dependencies have covered eg we can go to ML when python and Data preprocessing are covered 


/*
python
Pytorch
Dataset
Datapreprocessing
ML
DL
FaceRecogn*/