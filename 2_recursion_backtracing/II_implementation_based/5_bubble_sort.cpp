// but iterative codes are faster for bubble sort.
#include<iostream>
#include<ctime>
using namespace std;
bool compare(int a, int b)
{
    return a>b;
}
void bubble_sort_rec(int a[], int n)
{
    // base case, when n-1 elements gets sorted and only first starting element remains.
    if(n==1)
    {
     return;
    }// for loop ki starting me 5 4 3 2 1 tha 
    for(int j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    } // for loop ki end me 4 3 2 1 5 ho gya 
    bubble_sort_rec(a,n-1); // calling recursions for the next steps of bubble sort
}

// converting inner for loop also into recursion
void bubble_sort_rec_2(int a[], int n,int j)
{
    // base case, when n-1 elements gets sorted and only first starting element remains.
    if(n==1)
    {
        return;
    }
    if(j==n-1)
    {
        // reduce the problem size,and reset j to 0 
        bubble_sort_rec_2(a,n-1,0);
        return ;
    }
    if(a[j]>a[j+1])
    {
        swap(a[j],a[j+1]);
    }
    bubble_sort_rec_2(a,n,j+1);
}
int main()
{
    int arr[] ={-2,3,4,-1,5,-12,6,1,3};
    int n= sizeof(arr)/sizeof(int);
    //bubble_sort_rec(arr,n);
    bubble_sort_rec_2(arr,n,0);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}