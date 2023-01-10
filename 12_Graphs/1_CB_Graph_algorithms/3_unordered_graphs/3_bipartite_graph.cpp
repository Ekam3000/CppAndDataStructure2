// two coloring problem-> means the neighboring nodes should be on different sets. u give different colors to the neighbouring nodes 


// bipartite graph
// you can divide all vertices of graph in 2 set
// such that all edges of the graph are from set1 to set2

// with simple reasoning -> if the cycle is not present in the graph or the graph is a tree, then it will always a bipartite graph  

// if graph is cyclic and neighbouring nodes have diff colors then graph is bipertite


//not a bipertite -->

// if graph is cyclic and neighbouring nodes have same  colors then graph is not  bipertite

// if the graph is cyclic and contains odd number of nodes then graph is not bipertite

#include<bits/stdc++.h>
using namespace std;
bool dfs_helper(vector<int> graph[], int node , int *visited,int parent, int color)
{
    // come to node
    // remember visited node wala concept dfs traversal se aaya tha
    visited[node]=color; // 1 or2 , both mean visited
    for(auto nbr : graph[node])
    {
        // remember visited node wala concept dfs traversal se aaya tha
        if(visited[nbr]==0)  // so that a unvisited node will be covered 
        {
            int subprob = dfs_helper(graph, nbr , visited , node, 3- color); //3 -color -> if color is 1 then 3-color is 2 . if the color is 2 then 3-color is 1
            if(subprob == false)
            {
                return false;
            }
        }
        // bipartite me bhi node apne nbr (parent) ko visit nahi karta
        else if(nbr != parent and color == visited[nbr])
        // nbr aur parent ke diff color hi honge 
        // nbr != parent which makes sure that  color same ho sakta hai ab
        // color == color of current node .
        //visited[nbr] the one which is visited , is not parent of curr node and 
        {
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int N)
{
    int visited[N]={0}; // 0 -not visited 1-visited color is 1, 2-visited color is 2
    int color =1;
    int ans = dfs_helper(graph, 0, visited ,-1, color);
    // later one
    // colors
    for(int i=0; i<N; i++)
    {
        cout<<i<<"- color "<<visited[i]<<endl;
    }
    return ans;
}
 int main()
 {
   int N,M;// nodes and edges
   cin>>N>>M;

   vector<int> graph[N]; // array of N nodes .. each node has a vector container
   while(M--)
   {
    int x,y;
    cin>>x>>y;

    graph[x].push_back(y);
    graph[y].push_back(x);
   }
   // BFS or DFS , by coloring the nodes at each step (current node has color 1, nbr should have a color 2)
   if(dfs(graph,N))
   {
    cout<<"yes it is bipartite"<<endl;
   }
   else
   {
    cout<<"no it is bipartite"<<endl;
   }
   return 0;
 }
/*
    1
   / \
  2   3
  |   |
  4---5
*