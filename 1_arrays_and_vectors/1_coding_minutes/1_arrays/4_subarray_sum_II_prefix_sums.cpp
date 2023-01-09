#include<bits/stdc++.h>
using namespace std;
int  prefix_sum_subarray(int * arr, int n)
{
    int prefix[n]={0};
    prefix[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        prefix[i]= prefix[i-1]+arr[i];
    }
    int largest_sum=0;
    for(int i = 0; i < n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int curr_sum = i>0 ? prefix[j]-prefix[i-1] : prefix[j]; // if i=0 then we will return prefix[j]
            largest_sum=max(largest_sum,curr_sum);
        }
    }
    return largest_sum;
}
int main()
{
    int arr[] ={-2,3,4,-1,5,-12,6,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<prefix_sum_subarray(arr, n);
    return 0;
}