/*Problem Name: Friends Pairing Problem
Problem Difficulty: None
Problem Constraints: 1<= n < 30
Problem Description:
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Input Format: First line contains an integer t denoting the number of test cases.
Next t lines contain an integer n each.
Sample Input: 1
3
Output Format: Output t lines each line describing the answer.
Sample Output: 4



*/
// C++ program solution friends pairing problem
#include <bits/stdc++.h>
using namespace std;

// Returns count of ways n people can remain
// single or paired up.
long long countFriendsPairings(int n)
{
	long long dp[n+1];

	// Filling dp[] in bottom-up manner using
	// recursive formula explained above.
	for (int i=0; i<=n; i++)
	{
		if (i <= 2)
		dp[i] = i;
		else
		dp[i] = dp[i-1] + (i-1) * dp[i-2];
	}

	return dp[n];
}

// Driver code
int main()
{
	int n ,t;
	cin>>t;
	while(t>0)
	{
	    
    cin>>n;
	cout << countFriendsPairings(n) << endl;
	t--;
	}
	return 0;
}
