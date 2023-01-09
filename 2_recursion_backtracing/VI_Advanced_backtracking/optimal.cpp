/*how to use bitsmasks during backtracking
 N-queen problem
-print/count 1 config
-print/count all config

approaches -
1) naive backtracking approach
2) backtracking+bitsets(efficient) approach
3) backtracking+ bitmasks(more efficient)
*/
// for all configurations - u do not stop once u have found soln ..u keep on doing backtracking and try to generate more and more possibilities


#include <iostream>
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
// for counting number of configurations . initialize a global variable.
 
    int SolveNqueen(int board[][10], int i, int n)
    {
        if (i == n)
        { // base case
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
            return 1;
        }
        // recursive call
            // try to place the queen in the current row and call on the remaining part which will be solved by recursion. n=number od columns, number of queens , number of rows
            int cnt=0; // cnt is set for zero for every new row
        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, i, j, n))
            { // means i,j is the correct position
                board[i][j] = 1;
                cnt+=SolveNqueen(board, i + 1, n);
                board[i][j] = 0; 
            }
        }
        return cnt; // cnt return by every row to its previous upward row will be zero, if no such position/column exist in the current row. and 1 if a valid configuration occurs 
    }
    int main()
    {
        int n;
        cin >> n;
        int board[10][10] = {0};
        cout<<SolveNqueen(board, 0, n);
    }
    // when we remove the bool return type
    // so here irrespective of the remaining board was solved or not given by  SolveNqueen(board, i + 1, n); u will always place your queen at the next position/column.  
    // for n==8 we have 92 configurations.
    // overall complexity O(n) by isSafe function. now it will exponential complexity O(N^N).