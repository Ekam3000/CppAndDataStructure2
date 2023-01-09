#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> & a,int s, int e)
{
    int pivot=a[e];
    int i=s-1;
    for(int j=s;j<e;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
void quicksort(vector<int> &a, int s, int e)
{
    if(s>=e)
    {
        return;
    }
    // rec case
    int p=partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}
int quickselect(vector<int> a, int s, int e,int k)
{
    // assuming that k will be inside the array.
    int p=partition(a,s,e);
    if(p==k)
    {
        return a[p];
    }
    else if(k<p)
    {
        return quickselect(a,s,p-1,k);
    }
    else{
       return  quickselect(a,p+1,e,k);
    }
}
int main()
{
    vector<int> arr{10,5,2,0,7,6,4};
    int n=arr.size();
    //quicksort(arr,0,n-1);
    int k;
    cin>>k;
    cout<<quickselect(arr,0,n-1,k);
    return 0;
}