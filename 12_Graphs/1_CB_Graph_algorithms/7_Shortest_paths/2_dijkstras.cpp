#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> m;

public:
    void addEdge(T u, T v, int dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v, dist));
        if (bidir)
            m[u].push_back(make_pair(v, dist));
    }
    void printAdj()
    {
        // iterate over all the key value pairs in the map
        for (auto j : m)
        {
            cout << j.first << "->";
            // iterate over the list of cities
            for (auto l : j.second)
            {
                cout << "(" << l.first << "," << l.second << ")";
            }
            cout << endl;
        }
    }
    void dijkstraSSSP(T src)
    {
        unordered_map<T, int> dist;
        for( auto j:m)
        {
            dist[j.first] =INT_MAX;
        }
        // make a set to find a out node with the minimum distance
        set<pair<int, T>> s;
        dist[src] =0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            // find the pair at the front
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first();
            s.erase(s.begin());
            // iterate over neighbours/ children of the current node
            for(auto childPair : m[node])
            {
                if(nodeDist + childPair.second< dist[childPair.first])
                {
                    // in the set updation of a particular is not possible
                    // we have to remove the olsd pair , and insert the new pair to simulation updation
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f != s.end())
                    {
                        s.erse(f);
                    }
                    // insert the new pair
                    dist[dest]= nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        // lets print distance to all other nodee from src
        for(auto d: dist)
        {
            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }
    }
};
int main()
{
    /*
     Graph <int> g;
     g.addEdge(0,1,1);
     g.addEdge(1,3,3);
     g.addEdge(3,2,4);
     g.addEdge(2,0,2);
     g.addEdge(0,3,2);
     g.addEdge(1,2,2);
     g.printAdj();
     g.dijkstraSSSP(1);
     */

    Graph<string> india;
    india.addEdge("Amritsar", "Delhi", 1);
    india.addEdge("Amritsar", "Jaipur", 4);
    india.addEdge("Jaipur", "Delhi", 1);
    india.addEdge("Jaipur", "Mumbai", 1);
    india.addEdge("Bhopal", "Agra", 1);
    india.addEdge("Mumbai", "Bhopal", 1);
    india.addEdge("Agra", "Delhi", 1);
    india.printAdj();
    // india.dijkstraSSSP("Amritsar");
}