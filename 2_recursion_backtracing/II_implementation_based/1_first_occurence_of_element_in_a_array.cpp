#include <iostream>
using namespace std;

int First_occurence(int arr[], int n, int ele)
{
    if (n == 0)
    {
        return -1;
    }
    if (ele == arr[0])
    {
        return 0;
    }
    int subarray = First_occurence(arr+1, n - 1, ele);
    if (subarray != -1)
    {
        return subarray + 1;
    }
    else 
    return -1;
}
int main()
{
    int array[5] = {3, 4, 3, 6, 3};
    int ele = 3;
    cout << First_occurence(array, 5, ele);
}