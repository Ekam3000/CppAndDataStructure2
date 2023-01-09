/*
Code : K smallest Elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 
Constraints:
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
*/
#include <iostream>
using namespace std;
void kSmallestElements(int pq[], int n) {
	// Build the heap in input array
	for(int i = 1; i < n; i++) {
		int childIndex = i;
		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;
			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}
	// Remove elements
	int size = n;
	while(size > 1) {
		int temp = pq[0];
		pq[0] = pq[size - 1];
		pq[size-1] = temp;
		size--;
		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
		while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
	}
}
int main() {
    int n;
    cout<<"enter number of inputs\n :";
    cin>>n;
	int input[n];
	for(int i = 0; i < n; i++)
	{
		cin>> input[i];
        cout<<" ";
	}
    int k;
    cout<<"enter number of smallest elements:\n";
    cin>>k;
	kSmallestElements(input,n); 
    int array[k];
    int j=k-1;
    for(int i =(n-k);i <=(n-1); i++)
	{
		array[j--]=input[i];
	}
    for(int i = 0; i < k; i++)
	{
		cout<< array[i]<< " ";
	}
	// this will not work
	/*
	int j=0;
    for(int i =(n-1);i <=(n-k); i--)
	{
		array[j++]=input[i];
	}
    for(int i = 0; i < k; i++)
	{
		cout<< array[i]<< " ";
	}
	*/
	cout << endl;
}