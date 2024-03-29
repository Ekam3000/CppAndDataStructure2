/*Code : In-place heap sort
Send Feedback
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/


// In-place heap sort is used to reduce the space complexity . in heapSort our space complexity was O(n) we will try to reduce the space complexity by O(1).
#include <iostream>
using namespace std;
void inplaceHeapSort(int pq[], int n) {
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
	// 0 1 2 5 8 is the output after insersion
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
	int input[] = {5, 1, 2, 0, 8};
	inplaceHeapSort(input, 5);
	for(int i = 0; i < 5; i++)
	{
		cout<<input[i]<<" ";
	} 
	cout << endl;
}

   /* 
   5 ,1 , 2, 0 ,8 
     0
    / \
   1   2
  / \
  5  8
 // 0 1 2 5 8 is the output after insersion
 // 8 5 2 0 1 is the output after removing elements
*/
 
 /*
 10 5 8 1 4
     1
   /   \
  4     8
 /  \   
10   5
//  1 4 8 10 5 is the output after insersion
//10 8 5 4 1 is the output after removing elements
*/