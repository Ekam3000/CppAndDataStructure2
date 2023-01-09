#include<bits/stdc++.h>
using namespace std;
void printing_subarray(int * arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j=i; j<n; j++)
        {
            for(int k = i; k <= j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
// find out largest sum of subarray
// brute force
int  largest_sum_subarray(int * arr, int n)
{
    int largest_sum=0;
    for(int i = 0; i < n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int curr_sum=0;
            for(int k = i; k <= j;k++)
            {
                curr_sum+=arr[k];
            }
            largest_sum=max(largest_sum,curr_sum);
        }
    }
    return largest_sum;
}
int main()
{
    int arr[] ={-2,3,4,-1,5,-12,6,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
   // printing_subarray(arr, n);
   largest_sum_subarray(arr, n);
    return 0;
}