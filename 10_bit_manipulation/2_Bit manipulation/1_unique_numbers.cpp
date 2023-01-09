#include<bits/stdc++.h>
using namespace std;

int main()
{
// problem -Unique Number 2n +1;
// given a list of numbers where every numbers occurs twice except one, find 
int n;
cin>>n;
int no;
int ans=0;
//bitwise XOR operator to solve, helped to not any storage 
for(int i=0; i<n; i++)
{
    cin>>no;
    ans=ans^no;
}
cout<<ans<<endl;
}