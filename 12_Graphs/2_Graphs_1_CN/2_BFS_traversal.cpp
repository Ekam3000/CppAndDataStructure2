/*
Code : BFS Traversal
Send Feedback
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only.
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the BFS Traversal, as described in the task.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/
/*
#include <iostream>
#include <queue>
using namespace std;
void print(int **edges, int n, int sv, bool *visited)
{
    int datavalue;
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    while (pendingVertices.size() != 0)
    {
        if (datavalue == pendingVertices.front())
        {
            pendingVertices.pop();
            continue;
        }
        cout << pendingVertices.front();
        datavalue = pendingVertices.front();
        sv = pendingVertices.front();
        visited[sv] = true; // jo jo vertex visit hota jaye ga use mark as true karte jana
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == sv)
            {
                continue;
            }
            if (edges[sv][i] == 1)
            {
                if (visited[i])
                {
                    continue;
                }
                else
                    pendingVertices.push(i);
            }
        }
    }
}
int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false; // initially all the vertices are not visited .. so they marked as false
    }
    print(edges, n, 0, visited);
    // Delete all the memory
    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
*/
/*
7 8
0 1
0 2
1 3
1 4
2 6
3 5
4 5
6 5

0 1 2 3 4 6 5 */

#include<iostream>
#include<queue>
using namespace std;
void print(int** edges, int n, int sv, bool* visited){
  cout << sv << endl;
  visited[sv] = true; // jo jo vertex visit hota jaye ga use mark as true karte jana
  for(int i=0; i<n; i++){
    if(i==sv){
      continue;
    }
    if(edges[sv][i]==1){
      if(visited[i]){
        continue;
      }
      print(edges, n, i, visited);
    }
  }
}
void printBFS(int ** edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
    visited[i]=false;
    }
    pendingVertices.push(sv);
    visited[sv]=true;
    while (!pendingVertices.empty())
    {
         int currentvertex= pendingVertices.front();
         pendingVertices.pop();
        cout << currentvertex<<endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentvertex)
            {
                continue;
            }
            if (edges[currentvertex][i] == 1 &&!visited[i])
            {
                    pendingVertices.push(i);
                    visited[i]=true;
            }
        }
    }
    delete [] visited;
}
int main(){
  int n;
  int e;
  cin >> n >> e;
  int** edges = new int*[n];
  for(int i=0; i<n; i++){
    edges[i]=new int[n];
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }
  for(int i=0; i<e; i++){
    int f,s;
    cin >> f >> s;
    edges[f][s]=1;
    edges[s][f]=1;
  }
  bool* visited = new bool[n];
  for(int i=0; i<n; i++){
    visited[i]=false; // initially all the vertices are not visited .. so they marked as false
  }
  cout<<"DFS"<<endl;
  print(edges, n, 0, visited);
    cout<<"BFS"<<endl;
 printBFS(edges , n ,0);
  // Delete all the memory
  delete[] visited;
  for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
  return 0;
}
