/*
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0.
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
*/
#include <iostream>
#include <unordered_map>
using namespace std;
void counting_pairs(int *a, int size)
{
    int count = 0;
    unordered_map<int, int> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            seen[a[i]]=seen[a[i]] +1;
        }
        else
        seen[a[i]] = 1;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < seen.size(); j++)
        {

            if (seen[-a[i]])
            {
                count += seen[a[i]] * seen[-a[i]];
                seen.erase(a[i]);
                seen.erase(-a[i]);
            }
        }
    }
    cout << "number of pairs: " << count;
}
int main()
{
    int a[] = {-2, 2, 6, -2, 2, -6, 3};
    counting_pairs(a, 7);
}