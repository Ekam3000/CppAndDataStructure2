/*Aggressive Cows Problem
Send Feedback
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t - the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

// the search space is going to be a monotonic search space
/*
#include <iostream>
using namespace std;

int main()
{
    int stalls[] = {1, 2, 4, 8, 9};
    int n = 5;
    int cows = 3;
    // binary search algorithm
    int s = 0;
    int e = stalls[n - 1] - stalls[0];
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        cows--;
        int k = 0;
        for (int i = 1; i < n; i++)
        {

            if (mid <= (stalls[i] - stalls[k]))
            {
                cows--;
                k = i;
            }
        }
        if (cows == 0)
        {
            ans=mid;
            s = mid+1 ;
        }
        else
        {
            e = mid -1;
        }
    }
    cout << ans;
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int cows,long long positions[],int n,long long distance){

	int count = 1;
	long long last_position = positions[0];

	for(int i=1;i<n;i++){
		if(positions[i] - last_position >= distance){
			last_position = positions[i];
			count++;
		}

		if(count == cows){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,c;
		cin >> n >> c;

		long long positions[n];
		for(int i=0;i<n;i++){
			cin >> positions[i];
		}
		sort(positions,positions+n);
		long long start = 0;
		long long end = positions[n-1] - positions[0];
		long long ans = -1;
		while(start<=end){
			long long mid = start + (end-start)/2;

			if(check(c,positions,n,mid)){
				ans = mid;
				start = mid+1;
			}else{
				end = mid-1;
			}
		}
		cout << ans <<endl;
	}
	return 0;
}
