#include <iostream>
using namespace std;
int last_occurence(int arr[], int n, int ele)
{
    if (n == 0)
    {
        return -1;
    }
    int subindex = last_occurence(arr +1, n - 1, ele);
    if (subindex == -1)
    {
        if (ele == arr[0])
        {
            return 0;
        }
        else
            return -1;
    }
    else
       return  subindex + 1;
}
int main()
{
    int array[5] = {3, 4, 3, 6, 3};
    int ele = 3;
    cout << last_occurence(array, 5, ele);
}