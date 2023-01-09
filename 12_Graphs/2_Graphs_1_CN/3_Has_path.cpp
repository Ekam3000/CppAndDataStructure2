/*
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/
#include <iostream>
#include <queue>
using namespace std;
int Has_pathDFS(int **edges, int n, int sv, bool *visited, int s, int e, int flag)
{
  visited[sv] = true; // jo jo vertex visit hota jaye ga use mark as true karte jana
  for (int i = 0; i < n; i++)
  {
    if (i == sv)
    {
      continue;
    }
    if (edges[sv][i] == 1)
    {
      if (s == sv && e == i)
      {
        cout << "true";
        flag = 1;
      }
      if (visited[i])
      {
        continue;
      }
      s = i;
      Has_pathDFS(edges, n, i, visited, s, e, flag);
    }
  }
  return flag;
}
void Has_pathBFS(int **edges, int n, int sv, bool *visited, int s, int e)
{
  queue<int> pendingVertices;
  int flag = 0;
  pendingVertices.push(sv);
  visited[sv] = true;
  while (!pendingVertices.empty())
  {
    int currentvertex = pendingVertices.front();
    s = currentvertex;
    pendingVertices.pop();
    for (int i = 0; i < n; i++)
    {
      if (i == currentvertex)
      {
        continue;
      }
      if (edges[currentvertex][i] == 1 && !visited[i])
      {
        if (i == e)
        {
          cout << "true";
          flag = 1;
        }
        pendingVertices.push(i);
        visited[i] = true;
      }
    }
  }
  if (flag == 0 )
    cout << "false" << endl;
}
void BFS(int **edges, int n, int s, int e)
{
  int j=1;
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && j==1)
      Has_pathBFS(edges, n, i, visited, s, e);
      j=2;
  }
  delete[] visited;
}
void DFS(int **edges, int n, int s, int e)
{
  int j=1;
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && j==1)
    {
      int flag=0;
      int result = Has_pathDFS(edges, n, i, visited, s, e, flag);
      if (result == 0)
      {
        cout << "false"<<endl;
      }
      j=2;
    }
  }
  delete[] visited;
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
  int start, end;
  cout << "enter starting vertex and endind vertex for has_path:\n";
  cin >> start >> end;
  cout << "DFS" << endl;
  DFS(edges, n, start, end);
  cout << "BFS" << endl;
  BFS(edges, n, start, end);
  // Delete all the memory
  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
  return 0;
}