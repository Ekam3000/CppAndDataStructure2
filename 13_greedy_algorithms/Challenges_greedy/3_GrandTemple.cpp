/*
Problem Name: Grand Temple
Problem Difficulty: None
Problem Constraints: 1 <=  N <= 10^5 <br>
| Ai | <= 10^9
Problem Description:
A religious king wants to build the largest temple in his kingdom . To build the largest temple he needs to find the area of the largest suitable land . Given co-ordinates which denotes rivers flowing through the point horizontally as well as vertically , find the largest area possible to make the grand temple. <br>
Consider 2 rivers flowing across x-axis as well as y-axis. The temple must be enclosed by rivers on all 4 sides.
![pic](https://i.imgur.com/hhnZpEJ.png)

Input Format: An integer n denoting number of co-ordinates followed by n co-ordinates
Sample Input: 3
1 1
2 4
5 2
Output Format: Largest possible area to build the grand temple
Sample Output: 2



=====Solution=====
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    vector<ll> x;
    vector<ll> y;

    x.push_back(0);
    y.push_back(0);

    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;

        x.push_back(a);
        y.push_back(b);
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    ll deltaX = 0;
    for(ll i=1;i<x.size();i++){
        ll diff = x[i] - x[i-1] - 1 ;
        deltaX = max(deltaX,diff);
    }

    ll deltaY = 0;
    for(ll i=1;i<y.size();i++){
        ll diff = y[i] - y[i-1] - 1 ;
        deltaY = max(deltaY,diff);
    }

    //cout << "del X = "<<deltaX << "     del Y ="<< deltaY <<endl;
    ll maxArea = deltaX * deltaY ;
    cout << maxArea ;


    return 0;
}
