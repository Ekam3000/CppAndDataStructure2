/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
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
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2:
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
   0
 /   \
 1    3
  \  / \
   2    4
    \
     5
      \
       6
*/
void getPath(int **edges, int n, int sv, bool *visited, int s, int e, vector<int> output)
{
  if (s == e)
  {
    output.push_back(s);
    for(int i=s; i<n;i++)
    {
      visited[i]= true;
    }
    return;
  }
  visited[sv] = true; // jo jo vertex visit hota jaye ga use mark as true karte jana
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
      if(s==sv)
      {
        output.push_back(s);
        s = i;
      }
       getPath(edges, n, i, visited, s, e,output);
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
  int start, end;
  cout << "enter start index and end index:\n";
  cin >> start >> end;
  vector<int> output;
  getPath(edges, n, 0, visited, start, end,output);
  int i = 0;
  do
  {
    cout << output[i] << "\t";
  } while (output[i++] != end);

  // Delete all the memory
  delete[] visited;
  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
  return 0;
}
/*
   0
 /   \
 1    3
  \  / \
   2    4
    \
     5
      \
       6
*/