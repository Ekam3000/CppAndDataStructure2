// continue doing binary search 
// if key->mid , go to left part of the array
// this is the logic for the lower bound of the element

//

#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> arr, int key)
{
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            e=mid-1;
        } // modification in banary search in line 20,21
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }

    }
    return ans;
}

int upper_bound(vector<int> arr, int key)
{
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            s=mid+1;
        } // modification in banary search in line 46,47
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }

    }
   return ans;
}
int main()
{
    vector<int> arr={0,1,1,2,3,3,3,3,4,5,5,5,20};
    int n=arr.size();
    cout<<upper_bound(arr,3) - lower_bound(arr,3) +1 <<endl;
    return 0;
}