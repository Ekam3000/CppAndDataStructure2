
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class SnakesAndLadder
{
private:
    int n; //Size of board
    map<int, vector<int>> adjList;

public:
    SnakesAndLadder() {}

    void addEdge(int u, int v)
    {
        adjList[u].pb(v);
        // adjList[v].pb(u);
    }

    int solveGame(int src, int dest)
    {
        queue<int> q;
        map<int, int> dist;
        map<int, int> parent;
        q.push(src);
        for (auto i : adjList)
        {
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;
        parent[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (dist[adjList[node][0]] == INT_MAX)
            {
                q.push(adjList[node][0]);
                dist[adjList[node][0]] = dist[node];
                parent[adjList[node][0]] = node;
            }

            for (int v = 1; v < adjList[node].size(); v++)
            {
                int child = adjList[node][v];

                if (dist[child] == INT_MAX)
                {
                    q.push(child);
                    dist[child] = dist[node] + 1;
                    parent[child] = node;
                }
            }
        }

        if (dist[dest] == INT_MAX)
            return -1;
        return dist[dest];
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        const int n = 101;
        SnakesAndLadder g;

        int board[n] = {0};
        pair<int, int> p;

        int ladders; //No of ladders on the board
        cin >> ladders;

        for (int i = 0; i < ladders; i++)
        {
            cin >> p.first >> p.second;
            board[p.first] = p.second - p.first;
        }

        int snakes; //No of snakes on the board
        cin >> snakes;

        for (int i = 0; i < snakes; i++)
        {
            cin >> p.first >> p.second;
            board[p.first] = p.second - p.first;
        }

        //for(int i=0;i<n;i++){            cout << "board["<<i<<"] = "<<board[i] << endl ;        }

        for (int u = 0; u < n; u++)
        {
            //At every node , you can throw a dice
            for (int dice = 0; dice <= 6; dice++)
            {
                int v = u + dice + board[u + dice];
                if (v >= n) //Overflow condition
                    continue;
                g.addEdge(u, v);
            }
        }

        // g.printAdjList() ;

        cout << g.solveGame(0, n - 1) << endl;
    }

    return 0;
}


/*
Problem Name: Snake and Ladders Board (BFS)
Problem Difficulty: None
Problem Constraints: 1 < t < 20
1< n,l,s < 50
Problem Description:
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. The player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.


Input Format: First line contains integer t as number of test cases.
Each test case contains following input. First line contains three integers n, l, s which represents the number of cell of board, number of ladders and number of snakes.
Following l lines contains the description of ladders and next s lines contains description of snakes.

<img src="https://images.codingblocks.com/img/snakes_and_ladders.jpg" height="400" >
Sample Input: 1
30 4 4
3 22
5 8
11 26
20 29
17 4
19 7
21 9
27 1
Output Format: For each test case you have to print the number which is equal to the minimum number of dice throws to reach the last cell. 

Sample Output: 3
*/
/*
// C++ program to find minimum number of dice throws required to
// reach last cell from first cell of a given snake and ladder
// board
#include<iostream>
#include <queue>
using namespace std;

// An entry in queue used in BFS
struct queueEntry
{
	int v;	 // Vertex number
	int dist; // Distance of this vertex from source
};

// This function returns minimum number of dice throws required to
// Reach last cell from 0'th cell in a snake and ladder game.
// move[] is an array of size N where N is no. of cells on board
// If there is no snake or ladder from cell i, then move[i] is -1
// Otherwise move[i] contains cell to which snake or ladder at i
// takes to.
int getMinDiceThrows(int move[], int N)
{
	// The graph has N vertices. Mark all the vertices as
	// not visited
	bool *visited = new bool[N];
	for (int i = 0; i < N; i++)
		visited[i] = false;

	// Create a queue for BFS
	queue<queueEntry> q;

	// Mark the node 0 as visited and enqueue it.
	visited[0] = true;
	queueEntry s = {0, 0}; // distance of 0't vertex is also 0
	q.push(s); // Enqueue 0'th vertex

	// Do a BFS starting from vertex at index 0
	queueEntry qe; // A queue entry (qe)
	while (!q.empty())
	{
		qe = q.front();
		int v = qe.v; // vertex no. of queue entry

		// If front vertex is the destination vertex,
		// we are done
		if (v == N-1)
			break;

		// Otherwise dequeue the front vertex and enqueue
		// its adjacent vertices (or cell numbers reachable
		// through a dice throw)
		q.pop();
		for (int j=v+1; j<=(v+6) && j<N; ++j)
		{
			// If this cell is already visited, then ignore
			if (!visited[j])
			{
				// Otherwise calculate its distance and mark it
				// as visited
				queueEntry a;
				a.dist = (qe.dist + 1);
				visited[j] = true;

				// Check if there a snake or ladder at 'j'
				// then tail of snake or top of ladder
				// become the adjacent of 'i'
				if (move[j] != -1)
					a.v = move[j];
				else
					a.v = j;
				q.push(a);
			}
		}
	}

	// We reach here when 'qe' has last vertex
	// return the distance of vertex in 'qe'
	return qe.dist;
}

// Driver program to test methods of graph class
int main()
{
	// Let us construct the board given in above diagram
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int moves[n];
		for(int j=0;j<n;j++)
		{
			moves[j]=-1;
		}
		for(int j=0;j<m;j++)
		{
			int k1,k2;
			cin>>k1>>k2;
			moves[k1-1]=k2;
		}
		for(int j=0;j<k;j++)
		{
			int k1,k2;
			cin>>k1>>k2;
			moves[k1-1]=k2;
		}
		cout << getMinDiceThrows(moves, n)<<endl;
	}
	// int N = 30;
	// int moves[N];
	// for (int i = 0; i<N; i++)
	// 	moves[i] = -1;

	// // Ladders
	// moves[2] = 21;
	// moves[4] = 7;
	// moves[10] = 25;
	// moves[19] = 28;

	// // Snakes
	// moves[26] = 0;
	// moves[20] = 8;
	// moves[16] = 3;
	// moves[18] = 6;

	// cout << "Min Dice throws required is " << getMinDiceThrows(moves, N)<<endl;
	// return 0;
}

*/