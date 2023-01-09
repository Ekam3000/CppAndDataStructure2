#include<bits/stdc++.h>
using namespace std;
void swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Binary_search(int *array, int e, int l, int r)
{
    int mid=0;
    if(l>=r)
    {
        return -1;
    }
     mid=(l+r)/2;
    if(array[mid]==e)
    {
        swap(&array[mid],&array[0]);
        return mid;
    }
     if(array[mid]>e)
     {
        return Binary_search(array,  e, l, mid-1);
     }
     else if(array[mid]<=e)
     {
        return  Binary_search(array,  e, mid+1, r);
     }
    
    
}
int main()
{
    int array[]={2, 9,3, 18, 21, 16, 28, 28, 32};
    int n=sizeof(array)/sizeof(int);
    sort(array,array+n);
    cout<<"enter the searching element";
    int e;
    cin>>e;
    int l=0;
    int r=n-1;
    cout<<Binary_search(array,e,l,r);
    return 0;
}