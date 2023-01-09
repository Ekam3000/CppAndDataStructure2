/* given a MxN matrix, with some cella as blocked you have to-
1. find the path from start to end
2. count the number of paths from start to end
3. print all possible paths
 given rat can move only forward or downwards.


 // problem ends when source and dest are same block. i.e i=m-1 and j=n-1.
 // at each step rat either skips one row(when moves downwards) or one column(when moves forward)
 // two function go right and go down .. function calling depends upon whether if we want path exists then call go right function if returns true else u call go down function. if go down returns true then we hence know that multiple paths exists.
 // fill block with one if aage ka raasta exists
 // fill block withwith 0 if from both go right and go down function we don't find any path.

*/
// printing all possible paths.




#include <iostream>
using namespace std;
bool rateInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n)
{
    if (i == m && j == n)
    {
        soln[m][n] = 1;
    // print path
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << soln[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return true;
    }
if (i > m || j > n)
{
    return false;
}
if(maze[i][j]=='X')
{
    return false;
}
    // assume soln exists through current cell
    soln[i][j]=1;
    bool  rightsuccess = rateInMaze(maze, soln, i, j + 1, m, n);// maze[i][j + 1] != 'X'will checked by if(maze[i][j)=='X') condition
    bool downsuccess = rateInMaze(maze, soln, i+1, j , m, n);
     
     soln[i][j]=0; // jab humne dono path ghum liye.
    
    if(rightsuccess || downsuccess)
    {
        return true;
    }
    return false;
}

int main()
{
    char maze[10][10] =        {        "0000",
                         "00X0", "000X", "0X00"};
    int soln[10][10] = {0};
   char ans= rateInMaze(maze, soln, 0, 0, 3, 3); // 3, 3 represents m-1 and n-1
    if(ans==false)
    {
        cout<<"path does not exists";
    }

    return 0;
}
