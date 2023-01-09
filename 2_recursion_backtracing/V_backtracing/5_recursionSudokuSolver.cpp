// given a NXN sudoku , N is a perfect square , write an algorithm which finds a possible solution.
// NXN , will have N subgrid and size of each subgrid is root(N)*root(N)
// every row should have number from 1 to 9.
// every column should have number from 1 to 9
// every subgrid should have number from 1 to 9.
#include <bits/stdc++.h>
using namespace std;
bool canPlace(int mat[][9], int i, int j, int n, int number)
{
    // for checking row
    for (int column = 0; column < n; column++)
    {
        if (mat[i][column] == number)
            return false;
    }
    // for checking column
    for (int row = 0; row < n; row++)
    {
        if (mat[row][j] == number)
            return false;
    }
    int rn = sqrt(n);
    /*   0,0 0,1 0,2
         1,0 1,1 1,2
         2,0 2,1 2,2  are the names of subgrid */
    //  (4,5)=(i,j)
    // to find subgrid we will do (i/3) and (j/3)
    // starting point of the subgrid.
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    for (int p = sx; p < sx + rn; p++)
    {
        for (int q = sy; q < sx + rn; q++)
        {
            if (mat[p][q] == number)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int mat[][9], int i, int j, int n)
{
    if (i == n)
    {
        // print the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // now see-- recursive case/ call par jaane se pehle aur kuch cases bhi honge kya
    // case row end
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n - 1);
    }
    // skip the pre filled cells
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }
    // rec cell
    // fill the current cell with possible options
    for (int number = 1; number <= n; number++)
    {
        if (canPlace(mat, i, j, n, number))
        {
            mat[i][j] = number;
            bool nextCell = solveSudoku(mat, i, j + 1, n);
            if (nextCell)
            {
                return true;
            }
            mat[i][j] = 0;
        }
    } // agar return true na hua then backtrack kro, backtrack jab kare ge jab humne saare numbers try kar liye for particular cell
    
    // u have tried all number in the current cell , but couldn't find a match
    return false;
}

int main()
{
    int mat[9][9]= {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    solveSudoku(mat, 0, 0, 9);
}