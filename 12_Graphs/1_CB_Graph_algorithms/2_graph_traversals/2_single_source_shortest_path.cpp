#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T,list<T>> l;
    public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src)
    {
     map<T,int> dist;
     queue<T> q;

     // all other nodes will have int_max
     for(auto node_pair: l )
     {
        T node =node_pair.first;
        dist[node] +INT_MAX;
     }
     q.push(src);
     dist[src]= 0;
     while(!q.empty())
     {
        T node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr : l[node])
        {
            if(dist[nbr]==INT_MAX)
            {
                q.push(nbr);
                // mark that nbr as visited
                dist[nbr] =dist[node]+1;
            }
        }
     }
     // print the dist to every node
     for(auto node_pair :l)
     {
        T node = node_pair.first;
        int d = dist[node];
        cout<<"Node "<<node<<" Dist from scr "<<d<<endl;
     }
    }
};
int main()
{

}