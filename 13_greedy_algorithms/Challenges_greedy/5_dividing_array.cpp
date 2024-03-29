/*
@csalgo

Problem Name: Dividing Array
Problem Difficulty: None
Problem Constraints: 1<=T<=10 <br>
1<=n<=10^5 <br>
|Ai|<=10^9
Problem Description:
You are given an array, A, of n elements. You have to remove exactly n/2 elements from array A, and add it to another array B(initially empty). After these operations, you can rearrange the elements of both the arrays in any order. We define, difference between these two arrays as : <br>
<img src="https://images.codingblocks.com/img/equaimage.png" height="110">
<br>
Find the maximum and minimum values of differences of these two arrays.

Input Format: First Line contains number of test cases, T. For each test case, first line contains a single integer, n (n is even). Next line contains n integers, denoting the elements f array, A.
Sample Input: 1
4
12 -3 10 0

Output Format: For each test case, print the minimum and maximum value of differences between two arrays.
Sample Output: 5 25




=====Solution=====
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        ll maxDiff = 0;
        ll minDiff = 0;

        for (int i = 0; i < n / 2; i++)
        {
            maxDiff += (v[n - i - 1] - v[i]);
        }

        for (int i = 0; i < n; i += 2)
        {
            minDiff += (v[i + 1] - v[i]);
        }

        cout << minDiff << " " << maxDiff << endl;
    }

    return 0;
}