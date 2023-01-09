#include <iostream>
using namespace std;

bool isSorted(int arr[],int n)
{
    // base case
    if(n==1 or n==0)
    {
        return true;
    }
    if(arr[0]<=arr[1] and isSorted(arr+1,n-1))
    {
        return true;
    }
    return false;
}
int main()
{
    int array[5]={1, 2, 2, 4, 5};
    cout<<isSorted(array,5);
}