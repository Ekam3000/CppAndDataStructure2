/*Problem Name: 
Problem Difficulty: 
Problem Constraints: 1 <= V <= 10000 <br>
1 <= E <= 100000 <br>
0 <= Weight of each edge <= 10000
Problem Description:
Given an undirected weighted graph with V nodes and E edges , find the weight of the minimum spanning tree. 
The IDs of the nodes are between 0 and n-1 inclusive.<br><br><br>
Note : Try using both Kruskal and Prim's Algorithm for this problem

Input Format: First line contains two integers V and E. <br>
Next E lines contain three space separated integers - u ,v and w  <br>
u and v are the nodes , w = weight of edge
Sample Input: 4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40
Output Format: Display a single integer denoting the total weight of the minimum spanning tree.
Sample Output: 17


*/
=====Solution=====
#include <bits/stdc++.h>
using namespace std;

#define sync                          
    ios_base::sync_with_stdio(false); 
    cin.tie(0);                       
    cout.tie(0);

class Edge
{
public:
    int src;
    int dest;
    int wt;
};

class Set
{
public:
    int rank;
    int parent;
};

int find(Set *set, int i)
{
    if (set[i].parent != i)
        set[i].parent = find(set, set[i].parent);

    return set[i].parent;
}

void Union(Set *set, int u, int v)
{
    int uRoot = find(set, u);
    int vRoot = find(set, v);
    if (set[uRoot].rank < set[vRoot].rank)
    {
        set[uRoot].parent = vRoot;
    }
    else if (set[uRoot].rank > set[vRoot].rank)
    {
        set[vRoot].parent = uRoot;
    }
    else
    {
        set[vRoot].parent = uRoot;
        set[uRoot].rank++;
    }
}

bool myCompare(Edge a, Edge b)
{
    return a.wt < b.wt;
}

long long int Kruskals(Edge *inp, int n, int e)
{
    sort(inp, inp + e, myCompare);
    Edge *out = new Edge[n - 1];
    Set *set = new Set[n];
    for (int i = 0; i < n; i++)
    {
        set[i].rank = 0;
        set[i].parent = i;
    }

    int counter = 0;
    int i = 0;
    while (counter < n - 1)
    {
        Edge currentEdge = inp[i];
        int srcParent = find(set, currentEdge.src);
        int destParent = find(set, currentEdge.dest);
        if (srcParent != destParent)
        {
            out[counter] = currentEdge;
            Union(set, srcParent, destParent);
            counter++;
        }
        i++;
    }

    long long int totalWeight = 0;
    for (int j = 0; j < n - 1; j++)
    {
        totalWeight += (long long int)out[j].wt;
    }


    return totalWeight;
}

int main()
{
    sync;
    int V;
    cin >> V;

    int e;
    cin >> e;

    Edge *edge = new Edge[e];

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].src = u;
        edge[i].dest = v;
        edge[i].wt = w;
    }

    long long int mstWeight = Kruskals(edge, V, e);
    cout << mstWeight;

    return 0;
}