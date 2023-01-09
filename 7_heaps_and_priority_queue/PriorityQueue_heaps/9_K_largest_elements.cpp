/*Code : K largest elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25
*/
#include <iostream>
using namespace std;
void kLargestElements(int pq[], int n) {
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
    cout<<"enter number of largest elements:\n";
    cin>>k;
	kLargestElements(input,n); 
    int array[k];
    int j=k-1;
    for(int i =0;i <(k); i++)
	{
		array[j--]=input[i];
	}
    for(int i = 0; i < k; i++)
	{
		cout<< array[i]<< " ";
	}
}
