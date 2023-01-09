#include <bits/stdc++.h>
using namespace std;
int Binary_search(int *array, int e, int n)
{
   int l = 0;
   int r = n - 1;
   int mid;
   while (l <= r)
   {
      mid = (l + r) / 2;
      if (array[mid] == e)
      {
         return mid;
      }
      if (array[mid] > e)
      {
         r = mid - 1;
      }
      else if (array[mid] <= e)
      {
         l = mid + 1;
      }
   }
   return -1;
}
int main()
{
   int array[] = {2, 9, 3, 18, 21, 16, 28, 28, 32};
   int n = sizeof(array) / sizeof(int);
   sort(array, array + n);
   cout << "enter the searching element";
   int e;
   cin >> e;
   cout << Binary_search(array, e, n);
   return 0;
}