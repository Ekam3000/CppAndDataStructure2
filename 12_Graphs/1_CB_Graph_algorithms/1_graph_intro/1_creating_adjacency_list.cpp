#include <bits/stdc++.h>
using namespace std;
// searching O(1) , inserting values in adjancency matrix O(n^2) ,
// finding neighbours of  a node O(n)
// max number of egdes in a graph (if every node is connected with every other node) nC2 
// minimum number of edges in a graph are 0 . for a connected graph these are (n-1) edges and this type of graph is also called tree

// graph representation can also be done in stroing the edges[(0,1),(0,2),(1,2)] and vertices called the edges and vertices representation


// adjacency list --> 
// finding neighbours of  a node O(no. of neighbours)


// impilit graph is a kind of 2-D adj matrix..(insertion of 0 and 1's in it ) to find out number of connected components in the number of 1's in it 
class Graph
{
    int V;
    // array  of list
    list<int> *l;
  // we dont know the size so we created pointer .. dynamically allocation will be done later 
public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; // means hame V number of  lists chahiye of the type int  
    }
    void addEdge(int x, int y) // the edges will be bidirectional 
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjList()
    {
        // iterate over all the vectices
        for (int i = 0; i < V; i++)
        {
            cout << "vertex " << i << " "
                 << "->";
            for (int nbr : l[i])
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(4); // numbe rof vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();
}