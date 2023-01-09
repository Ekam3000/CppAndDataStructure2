#include <iostream>
using namespace std;
void print(int **edges, int n, int sv, bool *visited)
{
  cout << sv << endl;
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
      print(edges, n, i, visited);
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
/*
4
3
0 2
2 1
1 3

7
6
        0
      /   \
     1     2
    /     /  \
   5     3    6
    \
     4
     output--> 0 1 5 4 2 3 6
7
7
        0
      /   \
     1     2
    /     /  \
   5     3    6
    \  /
     4
      output--> 0 1 5 4 3 2 6
*/