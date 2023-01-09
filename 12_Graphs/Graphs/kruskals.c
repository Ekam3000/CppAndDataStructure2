#include <stdio.h>
#define I 65535
int edge[9][3] = {{1, 2, 28}, {1, 6, 10}, {2, 3, 16}, {2, 7, 14}, {3, 4, 12}, {4, 5, 22}, {4, 7, 18}, {5, 6, 25}, {5, 7, 24}};
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; // 8 size set dipicting no. of vertices +1 // set[] array is useful in depicting a parent of particular data value vertex and who is the actual parent 
int included[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // will maintain the record of the edges that are included in the array t[2][6]so far.
void join(int u, int v)
{
    if (set[u] < set[v]) // means set[u]  is a negative number but is greter in magnitude  then set[v]
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {   
        set[v] += set[u]; // if both set[u] and set[v] are -1 then automatically large data value wala element parent bne ga 
        set[u] = v;
    }
}
int find(int u) // find(u) helpful in depicting the parent of a data value vertex
{
    int x = u, v = 0;
    while (set[x] > 0) // set[] array is useful in depicting a parent of particular data value vertex and who is the actual parent if the particular data value array element corrresponds to -ve number
    {
        x = set[x];
    }
    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }// 26 se 29 takk extra code hai known as collapsing find
    return x;
}
int t[2][6]; 
int main(int argc, const char *argv[])
{
    int u = 0, v = 0, i, j, k = 0, min = 65535, n = 9;
    i = 0;
// j is the index at which we find a minimum weight edge
    while (i < 6)
    {
        min = 65535;
        for (j = 0; j < n; j++)
        { 
            if (included[j] == 0 && edge[j][2] < min)
            {
                u = edge[j][0]; // u is vertev number
                v = edge[j][1]; // v is a vertex number
                min = edge[j][2];
                k = j; // minimum weight edge ='s to k
            }
        }
        if (find(u) != find(v)) // find(u) helpful in depicting the parent of a data value vertex
        {
            t[0][i] = u;
            t[1][i] = v;
            join(find(u), find(v));
            included[k] = 1;
            i++;
            // printf("%d %d %d %d\n",u,v,find(u),find(v));
        }
        else
        {
            included[k] = 1; // if both data value have same parent
        }
    }
    printf("Spanning Tree\n");
    for (i = 0; i < 6; i++)
    {
        printf("%d %d\n", t[0][i], t[1][i]);
    }
    return 0;
}