// D and C
// nlogn on avg case
// n^2 worst case
// inplace algo , means sorting of array without using another array 
// requires extra space due to recursion call stack
#include <iostream>
using namespace std;
int Partition(int array[], int p, int r)
{
  int x = array[r]; 
  int i = p - 1;
  for (int j = p; j <= r - 1; j++)
  {
    if (array[j] <= x)
    {
      i++;
      swap(array[i], array[j]);
    } 
  }
  // place the pivot ele in the correct index
  swap(array[r], array[i + 1]);
  return i + 1;
}
void Quicksort(int array[], int p, int r)
{
  if (p >= r)
  {
    return;
  }
  int q = Partition(array, p, r);
  Quicksort(array, p, q - 1);
  Quicksort(array, q + 1, r);
}
int main()
{
  int arr[] = {2, 7, 8, 6, 1, 5, 4};
  Quicksort(arr, 0, 6);
  for (int i = 0; i < 6; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}