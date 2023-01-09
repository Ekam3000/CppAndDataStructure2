// rahul had a sorted array of numbers from which he had to find a given number quickly. gis friend by mistake rotated the array . now rahul doesn't have time to sort the elements again . help him to quickly find the given number from the rotated array.
#include <iostream>
using namespace std;

int find_index(int *arr, int n, int key)
{
int s=0;
int e=n-1;
while(s<=e)
{
    int mid=(s+e)/2;
    if(arr[mid]==key)   
    return mid;
    else if(arr[s]<=arr[mid])
    {
     // 2 cases-> element lies on the left or the right of the mid;
     if(key>=arr[s] && key<=arr[mid])
     {
        e=mid-1;
     }
     else
     s=mid+1;
    }
    // otherwise mid lies in second part 
    else
    {
        if(key>=arr[mid] && key<=arr[e])
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
}
return -1;
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<find_index(a,n,key);
    return 0;
}