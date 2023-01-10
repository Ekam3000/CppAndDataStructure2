// kosaraju's algorithm for strongly connected components
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[], int i, bool *visited, vector<int> & stack)
{
    visited[i] = true;
    for(auto nbr : graph[i])
    {
        if(!visited[nbr])
        {
            dfs(graph, nbr, visited, stack);
        }
    }
    // function call is complete
     stack.push_back(i); // when we are going bach from a node we are adding the node in the stack
}

void dfs2(vector<int> graph[], int i, bool * visited)
{
    visited[i] = true;
    cout<<i<<" ";
    for(auto nbr : graph[i])
    {
        if(!visited[nbr])
        {
            dfs2(graph, nbr, visited);
        }
    }
    
}
void solve(vector<int> graph[], vector<int> rev_graph[], int N)
{
    bool visited[N];
    memset(visited, 0, N); // setting the array visited of N elements as 0
    vector<int> stack;
    // step 1: need store the vertices acc to dfs finish time(once u are going back from a vertex)
    for(int i = 0; i < N; ++i)
    {
        if(!visited[i])
        {
            dfs(graph, i, visited, stack); // all the components will be placed in the stack
        }
    }
    // ordering = stack
    

    // step 2: reverse

    // step 3: do dfs acc to ordering given in the stack
    // visiting again the graph for the second time.
    memset(visited, 0, N);
    char component_name ='A'; 
    for(int x= stack.size()-1; x >= 0; x--)
    {
        int node = stack[x];
        if(!visited[node]) // nodes then are marked as true by dfs2 will not be visited here so we get one connected component as 0 1 2
        {
            cout<<" component "<<component_name<<"-->";
            // there is component starting from this node
            dfs2(rev_graph, node, visited);
            cout<<endl;
            component_name++; 
        }
    }
}
int main(int argc, char** argv)
{
    int N;
    cin>>N;
    vector<int> graph[N];
    vector<int> rev_graph[N];

    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    solve(graph,rev_graph,N);
}

 /*
       1-->0 ------------>   3-->5
 2 to 1|   | 0 to 2    6 to 3|   | 5 to 6
       <-- 2           3 to 4|<--6
 */                     //   4
// strongly connected component of a graph
// if in a graph there is a component , where starting from any vertex we can reach every vertex of the component.

// 1.start from any node  DFS, get an ordering based upon finish time.the node which is finished at last will be placed at the end of the vector
// 6 5 4 3 1 2 0

//2. reverse the graph . in which all the edges of the graph gets reversed.
// 3. Do DFS from R to L as given in ordering list(important from right to left )
//c1 0, 1,2 (while we call a dfs traversal from 0 from ordered list we are just limited to nodes 0,1,2 only )

//c2 3 6 5 

//c3 4 ->remains as a single 
// these are the connected components

// if in a graph y is reachable by x .. then in the ordering list x should come after y

/*
7 8
2 1
1 0
0 3
0 2
3 5
5 6
6 3
3 4*/