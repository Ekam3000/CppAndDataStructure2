#include <bits/stdc++.h>
using namespace std;
// base case is the one , in which the problem depends on the variables which are changing.

// capacity of the thief's bag is fixed 
// target - the thief want to maximize his profit
// N - number of items 
int P01knapsack(int *weight, int *profit, int N, int C)
{
    if (N == 0 || C == 0)
    {
        return 0;
    }
    // in order to maximise the profit , we have to look upon whether to include that item or to exclude that item.
    int ans = 0;
    int inc, exc; // include ,exclude
    inc = 0;
    exc = 0;
    if (weight[N - 1] <= C) // har step me saath ki saath capacity bhi kamm ho rahi hai.
    {
        inc = profit[N - 1] + P01knapsack(weight, profit, N - 1, C - weight[N - 1]);
    }
    exc = P01knapsack(weight, profit, N - 1, C);

    ans = max(inc, exc);
    return ans;
}
int main()
{
    int weight[] = {2, 5, 10, 5};
    int profit[] = {40, 30, 50, 10};
    int N = 4;
    int C = 16;
    cout << P01knapsack(weight, profit, N, C);
}