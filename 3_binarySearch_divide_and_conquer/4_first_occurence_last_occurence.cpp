#include <bits/stdc++.h>
using namespace std;
int first_occurence(int *array, int e, int n)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (array[mid] == e)
        {
            ans = mid;
            r= mid - 1;
        }
        else if (array[mid] > e)
        {
            r = mid - 1;
        }
        else if (array[mid] <= e)
        {
            l = mid + 1;
        }
    }
    return ans;
}

// last occurence
int last_occurence(int *array, int e, int n)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (array[mid] == e)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (array[mid] > e)
        {
            r = mid - 1;
        }
        else if (array[mid] <= e)
        {
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int array[] = {1, 2, 3, 8, 8, 8, 8, 8, 10, 12, 15, 20};
    int n = sizeof(array) / sizeof(int);
    sort(array, array + n);
    cout << "enter the searching element";
    int e;
    cin >> e;
    cout << first_occurence(array, e, n);
    cout << last_occurence(array, e, n);
    return 0;
}