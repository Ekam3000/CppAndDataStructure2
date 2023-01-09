/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/
#include <iostream>
#include <unordered_map>
using namespace std;
int Max_freq(int* a, int size) {
	int max= -1;
	unordered_map<int,int> seen;
	for (int i = 0; i < size; i++) {
		if (seen.count(a[i]) > 0) {
			seen[a[i]]++;
		}
        else
		seen[a[i]] =1;
	}
    int i=0;
    while(seen.size())
    {
        if(seen[a[i]]>max)
        {
            max=seen[a[i]];
        }
            seen.erase(a[i]);
            i++;
    }
	return max;
}
int main() {
	int a[] = {1,2,3,3,2,1,2,3,6,5,5};
	int max_freq = Max_freq(a, 11);
	cout<<"max frequency number: "<<max_freq;
}
