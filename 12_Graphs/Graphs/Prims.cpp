#include <iostream>
#define I 32767
using namespace std;
int cost[][8] =
    {{I, I, I, I, I, I, I, I},
     {I, I, 25, I, I, I, 5, I},
     {I, 25, I, 12, I, I, I, 10},
     {I, I, 12, I, 8, I, I, I},
     {I, I, I, 8, I, 16, I, 14},
     {I, I, I, I, 16, I, 20, 18},
     {I, 5, I, I, I, 20, I, I},
     {I, I, 10, I, 14, 18, I, I}};
int near[8] = {I, I, I, I, I, I, I, I}; // used for telling who is connected and who is minimum
int t[2][6];                            // for 7 vertices we have 6 edges
int main()
{
    int i, j, k, u, v, n = 7, min = I;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for (i = 1; i <= n; i++) // i<=n is saying u have to check upto number of vertices
    {
        if (near[i] != 0)
        {
            /*  example -->
              cost[2][1] <  cost[2][6]
              cost[3][1] <  cost[3][6]
              cost[4][1] <  cost[4][6]
              cost[5][1] <  cost[5][6] .....
              */
            if (cost[i][u] < cost[i][v]) // checking a particular vertex(all other vertices except 1 and 6 for the first time) is nearer to whom (which are selected there at top for loop u and v).. jitna chotta min cost edge hoga utna hi nearer vo uss vertex ke hoga
                near[i] = u;
            else
                near[i] = v;
        }
    }
    // repeated loop
    for (i = 1; i < n - 1; i++) // now we are selecting min cost edge between the vertices of  which we have set up (connect up ) to their nearer min  cost value in the above for loop  . the one connection which will be smallest cost edge with the predefined near[]= 0 box will make a new edge for example vertex 5 makes an edge with the vertex 6.
    {
        min = I;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {          // near[j] represents a vertex value to which near index value vertex is nearer
                k = j; // we have gor our near (min)cost edge index.
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]]) // example k =5 .. and we are compare index 4 of near[] arrey element value(i.e 6) with the index 5  (4->6 with 4->5  ) if 4->5 connection is min than 4->6 connection then index 4 of near[] array element is updated
                near[j] = k;
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }
}
/*
  1
/     \
/        2
6      /  |
/    7     |
/  /  |     3
/ /    |   /
5       | /
 4

 */
