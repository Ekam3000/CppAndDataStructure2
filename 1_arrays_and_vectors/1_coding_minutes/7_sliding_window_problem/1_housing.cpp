#include<bits/stdc++.h>
using namespace std;
void housing (int *arr, int n , int k)
{
    int i=0;
    int j=0;
    int cs=0;
    while(j<n)
    {
        // expand to right
        cs += arr[j];
        j++;
        //remove elements from the left till cs > sum and i< j
        while(cs > k and i< j)
        {
            cs = cs - arr[i];
            i++;
        }
        // check if any given point
        if(cs ==k)
        {
            // print that window
            cout<<i<<"-"<<j-1<<endl;
        }
    }
    return ;
}

int main()
{
    int plots[] ={1,3,2,1,4,1,3,2,1,1};

    int n = sizeof(plots)/sizeof(plots[0]);

    int k=0;
    housing(plots,n,k);
}
// homework -find the smallest window that contain the required sum 
// handle if u have negative integers in the array