#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y); // only directed edge we have 
        //bcoz edge ka create hona dice ke through ke upar depends 
    }
    int bfs(T src, T dest)
    {
        map<T, int> dist;
        map<T,T> parent;
        queue<T> q;

        // all other nodes will have int_max
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX; // all the nodes sets to distance inf
        }
        q.push(src);
        dist[src] = 0; 
        parent[src]=src; // parent of source is source 
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (int nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    // mark that nbr as visited
                    dist[nbr] = dist[node] + 1; // all the neighbors are at dist 1 if node is 0
                    parent[nbr] = node; // parent of neighbor's is node(that are directly connected to node ) .. which makes a change in the dist[nbr] a
                }
            }
        }
        for(auto node_pair : l)
        {
            cout<<node_pair.first<<" and dist "<<dist[node_pair.first]<<endl;
        }
        T temp =dest;
        while(temp != src)
        {
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;
        // print the dist to dest node
        return dist[dest]; //returning the dist of dest from source i.e 0.. source is that whose dist is set to zero initially 
    }
};
int main()
{
    // snakes // ladders
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    // add edges to the graph
    Graph<int> g;
    /*
    if we are at i , then from i we can have edge from i+1 to i+6
    // as 6 is the max number in the dice
    if there is an edge from i to i+2 , and at i+2 there is an ladder that take a number N (represented as board[i+2]=N). then then edge from i to i+2 is discarded and edge from i to i+2+N is constructed .. so i goes to i+2+N
    */
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice; // for i=36 j value will be indeed atleast 37. in that case a edge will not be constructed 
            j+= board[j];

            if (j <= 36)
            {
                g.addEdge(i, j); //example 1 to 15 is one edge if dice gives 1 . 
            }
        }
    }
    g.addEdge(36,36); // a edge for node 36 is created . so 36 node ki bhi entry ho jaye gi map me 

    cout <<g.bfs(0, 36); // source and dest node 
}

// Minimum Number of Dice Throws required to reach the destination 36 strating from the source 0 . find the shortest path as well.

// its a weighted graph or an unweighted graph ? 

// ans ->its an unweighted graph, every edge has an equal cost . that cost is equal to one dice throw . the distance b/w two nodes does not matter as the ques says minimum number of dice throws. so dist from 1 to 3 or 1 to 5 is just 1 (The one die throw)

// output galat aa rahi
