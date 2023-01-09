/*
Place the mirror
Send Feedback
You are given a N x N grid, in which some cells are empty(denoted by '0') while some cells have rock in it(denoted by '1'). You are standing at the south side of the grid and you have to watch on the east side. You can place a mirror at 45 degrees on an empty cell in the grid, so that you could see on the east side of the grid.
But, if you found a rock in the line of sight, you won't be able to see anything on the east side.
You. have to tell how many possible cells are there in which you can place a mirror to watch on the east side.
Input Format:
The first line of input contains the size of the grid.
Next N lines contains N characters in each line (either '0' or '1' to denote empty or rock in a cell)
Output Format:
The output contains an integer denoting the number of possible options where mirror can be placed to see on the East side.
Constraints:
1<=N<=1000
Sample Input:
4
1 0 1 1
0 1 0 0
0 0 0 0
0 1 1 0
Sample Output:
4
Explanation:
The grid is:
  So here we have 4 possible cells where mirror can be placed to see on the East side.

*/