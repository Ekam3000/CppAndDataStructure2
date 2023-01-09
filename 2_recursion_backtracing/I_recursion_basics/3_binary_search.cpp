// recursive function to perform binary search
// return index
#include<iostream>
using namespace std;
int binary_search(int arr[],int ele,int lb, int ub)
{
if(lb>ub)
{
    return -1;
}
else if(arr[(lb+ub)/2] == ele)
{
    int mid = (lb+ub)/2;
    return mid;
}
else if(arr[(lb+ub)/2] < ele)
{
    int mid = (lb+  ub)/2;
    binary_search(arr, ele, mid+1, ub);
}
else 
{
    int mid = (lb+ ub)/2;
    binary_search(arr, ele, lb, mid-1);
}
}
int main()
{
   int arr[]={1,2,3,4,5,10,20};
   int ele = 1;
   cout<<binary_search(arr,ele,0,sizeof(arr));
}