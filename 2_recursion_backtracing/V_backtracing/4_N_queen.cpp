#include <bits/stdc++.h>
using namespace std;
bool isSafe(int board[][10], int i, int j, int n)
{
    // for checking column
    for (int row = 0; row < i; row++)
    {   // for checking column c, column ki value same i.e j
        if (board[row][j] == 1)
        {
            return false;
        }
    }
        // for same diagonal
        // left diagonal
        int x = i;
        int y = j;
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            x--;
            y--;
        }
        x = i;
        y = j;
        while (x >= 0 && y < n)
        {
            if (board[x][y] == 1)
            {
                return false;
            }
            x--;
            y++;
        }
        //  the position is now safe , return true.
        return true;
    
}
    bool SolveNqueen(int board[][10], int i, int n)
    {
        if (i == n)
        { // recursive call
            // try to place the queen in the current row and call on the remaining part which will be solved by recursion
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == 1)
                    {
                        cout << "Q"
                             << " ";

                    }
                    else
                    {
                        cout << "_";
                    }
                }
                cout << endl;
            }
            cout << endl;
            return true;
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, i, j, n))
            { // means i,j is the correct position
                board[i][j] = 1;
                bool nextQueenRakhPaye = SolveNqueen(board, i + 1, n);
                if (nextQueenRakhPaye)
                {
                    return true;
                }
                // means i,j is not the the correct position
                board[i][j] = 0; // backtrack.
            }
        }
        // means you have tried for all positions in the current row but couldn't place a queen
        return false;
    }
    int main()
    {
        int n;
        cin >> n;
        int board[10][10] = {0};
        SolveNqueen(board, 0, n);
    }
    // to print all configurations return false in the base case of SolveNQueen function becoz 
   /* if (nextQueenRakhPaye)
                {
                    return true;
                }
                becoz u will never get nextQueenRakhPaye as true .
                every row will think no configuration is possible
    */