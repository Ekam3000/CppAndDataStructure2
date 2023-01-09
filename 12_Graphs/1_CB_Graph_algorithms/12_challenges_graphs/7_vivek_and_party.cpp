/*
Approach
The problem is about simple BFS Topological Sort.
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

class Functor
{
public:
    bool operator()(string a, string b)
    {
        return mp[a] < mp[b];
    }
};

class Graph
{
private:
    map<string, list<string>> adjList;
    int V;

public:
    Graph(int n)
    {
        V = n;
        mp.clear();
    }

    void init(const vector<string> v)
    {
        for (int i = 0; i < V; i++)
        {
            adjList[v[i]];
            mp[v[i]] = i;
        }
    }

    void addEdge(const string &u, const string &v)
    {
        // adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void bfsTopologicalSort(const vector<string> &v)
    {
        priority_queue<string, vector<string>, Functor> q;
        map<string, bool> visited;
        map<string, int> indegree;
        for (auto it : v)
        {
            visited[it] = false;
            indegree[it] = 0;
        }

        for (auto it : adjList)
        {
            auto u = it.first;
            for (auto v : adjList[u])
            {
                indegree[v]++;
            }
        }

        for (auto i : adjList)
        {
            auto node = i.first;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        vector<string> order;

        int i = 0;
        while (!q.empty())
        {
            auto node = q.top();
            q.pop();
            order.push_back(node);
            i++;
            for (string x : adjList[node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }

        reverse(order.begin(), order.end());

        for (int i = 0; i < order.size(); i++)
        {
            cout << " " << order[i];
        }
        cout << ".";

        cout << endl;
    }

    ~Graph() {}
};

int main()
{
    int c = 1;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Graph g(n);
        vector<string> beverages(n);
        for (int i = 0; i < n; i++)
        {
            cin >> beverages[i];
        }

        g.init(beverages);

        int m;
        cin >> m;
        while (m--)
        {
            string a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }

        cout << "Case #" << c++ << ": Vivek should drink beverages in this order:";
        g.bfsTopologicalSort(beverages);

        cout << endl;
    }

    return 0;
}
