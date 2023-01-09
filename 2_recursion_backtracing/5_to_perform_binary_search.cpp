#include<iostream>
using namespace std;
int binary_search(int arr[],int ele,int start, int end)
{
if(start>end)
{
    return -1;
}
int mid=(start+end)/2;
if(arr[mid]==ele)
{
    return mid;
}
if(arr[mid]>ele)
{
     binary_search(arr,ele,start,mid-1);
}
else
  binary_search(arr,ele,mid+1,end);

}
int main()
{
    int arr[7]={1,2,3,4,5,10,20};
    cout<<binary_search(arr,2,0,6);
    return 0;
}