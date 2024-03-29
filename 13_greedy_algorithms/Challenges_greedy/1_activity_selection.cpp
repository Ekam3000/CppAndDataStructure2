/*
Problem Name: Activity Selection Problems
Problem Difficulty: None
Problem Constraints: 1<=t<=50<br>
1<=n<=10000<br>
1<=A[i]<=100
Problem Description:
You are given n activities (from 0 to n-1) with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time. 


Input Format: The first line consists of an integer T, the number of test cases. For each test case, the first line consists of an integer N, the number of activities. Then the next N lines contain two integers m and n, the start and end time of each activity.
Sample Input: 1 
3
10 20
12 15
20 30
Output Format: For each test case find the maximum number of activities that you can do.
Sample Output: 2



=====Solution=====
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, a, b;
		cin>>n;
		pair<int, int> arr[n];
		for(int i=0;i<n;i++) {
			cin>>a>>b;
			arr[i] = make_pair(a, b);
		}
		sort(arr, arr+n, cmp);
		// for(int i=0;i<n;i++) {
		// 	cout<<arr[i].first<<" "<<arr[i].second<<endl;
		// }
		int ans = 1, chosen = 0;
		for(int i=1;i<n;i++) {
			if(arr[i].first>=arr[chosen].second) {
				ans++;
				chosen = i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

