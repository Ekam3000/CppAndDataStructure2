/*
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/
#include<bits/stdc++.h>
using namespace std;
struct Job
{
    int start,finish,profit;
};
bool compare(Job a, Job b)
{
    return a.finish < b.finish;
}
int findMprofit(Job arr[], int n)
{
    sort(arr, arr+n, compare);
    int * dp = new int[n];
    dp[0]= arr[0].profit;

    for(int i=1; i<n; i++)
    {
        int including = arr[i].profit;
        int lNConflict =-1;
        for(int j=i-1; j>=0; j--)
        {
            if(arr[j].finish<=arr[i].start)
            {
                lNConflict=j;
                break;
            }
        }
        if(lNConflict != -1)
        {
            including +=dp[lNConflict];
        }
        dp[i]=max(including,dp[i-1]);
    }
    int ans =dp[n-1];
    delete [] dp;
    return ans;
}
int main()
{
Job arr[]={{2,5,50},{1,2,20},{6,9,70},{2,50,400}};
cout<<"Maximum Profit is"<<findMprofit(arr,4)<<endl;
}