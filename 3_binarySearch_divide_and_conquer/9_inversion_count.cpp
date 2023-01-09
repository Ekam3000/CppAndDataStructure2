/*
Inversion Count
Send Feedback
For a given integer array/list of size N, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair (arr[i], arr[j]) is said to be an inversion when,
1. arr[i] > arr[j] 
2. i < j

Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N).
Input format :
The first line of input contains an integer N, denoting the size of the array.

The second line of input contains N integers separated by a single space, denoting the elements of the array.
Output format :
The only line of output prints the total count of inversions in the array.
Note:
You are not required to print anything. Return the total number of inversion count.
Constraints :
1 <= N <= 10^5 
1 <= arr[i] <= 10^9

Time Limit: 1sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Input 1:
We have a total of three pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
*/
/*
1. divide array into two parts
2. merge sort left and right array. plus calculate the inversion count in respective arrays
3. count=left I.count + right I.count +count during merging.
*/
/*
#include<iostream>
using namespace std;
int merge(int *arr, int s1, int s2 ,int e)
{
    int count=0;
    int k=0;
    int i=s1;
    int j=s2;
    int temp[e-s1 +1];
    while(i<s2 && j<=e)// last element e ko bhi include karna
    {
     if(arr[i]>arr[j])
     {
        count += s2 -i;
        temp[k++]=arr[j];
     }
     else{
        temp[k++]=arr[i];
     }
    }
    while(i<s2)
    {
        temp[k++]=arr[i++];
    }
     while(j<=e) // last element e ko bhi include karna 
    {
        temp[k++]=arr[i++];
    }
    for(int i=s1,k=0;i<=e;i++)// last element e ko bhi include karna
    {
        arr[i]=temp[k++];
    }
    return count;

}
int merge_sort(int *arr, int s, int e)
{
    int count = 0;
    if(s>e)
    {
        return -1;
    }
    if(s<=e)
    {
    int mid=(s+e)/2;
        int leftcount=merge_sort(arr, s, mid);
        int rightcount=merge_sort(arr, mid+1, e);
        int overallcount=merge(arr,s, mid+1,e);
        count += leftcount + rightcount+overallcount;
    }
    return count;
}
int solve (int * array, int n)
{
    return merge_sort(array, 0, n-1);
}
int main()
{
    int A[] = {5,4,2,3,1};
	cout << solve(A,5);
	return 0;
}
*/
#include<iostream>
using namespace std;
long long merge(int A[],int left,int mid,int right){

	int i=left,j=mid,k=0;

	int temp[right-left+1];
	long long count = 0;
	while(i<mid && j<=right){
		if(A[i] <= A[j]){
			temp[k++] = A[i++];
		}else{
			temp[k++] = A[j++];
			count += mid - i;
		}
	}
	while(i<mid){
		temp[k++] = A[i++];
	}
	while(j<=right){
		temp[k++] = A[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++){
		A[i] = temp[k];
	}
	return count;
}
long long merge_sort(int A[],int left,int right){

	long long count = 0;
	if(right > left){
		int mid = (left + right)/2;
		long long countLeft = merge_sort(A,left,mid);
		long long countRight = merge_sort(A,mid+1,right);
		long long myCount = merge(A,left,mid+1,right);
		return myCount + countLeft + countRight;
	}
	return count;
}
long long solve(int A[], int n)
{
	long long ans = merge_sort(A,0,n-1);
	return ans;
}
int main(){
	int A[] = {5,4,2,3,1};
	cout << solve(A,5);
	return 0;
}