/*
Code : Print Intersection
Send Feedback
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.
*/
// without hashmaps
#include <iostream>
using namespace std;
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1;i++){
    int min=arr[i];
    int minIndex=i;
    for(int j=i+1;j<n;j++){
    //  if(arr[j]<min) for decreasing order. 
    if(arr[j]<min){
            min=arr[j];
            minIndex=j;
        }
    }
        int temp;
        temp=arr[i];
        arr[i]=min; // or arr[minIndex]
        arr[minIndex]=temp;
    }
}
int main() {
	int a[] = {6,2,6,2,1,9,8};
    int b[] ={3,6,8,2,9};
    selectionSort(a,7);
    selectionSort(b,5);
    int i=0 ,j=0;
    cout<<"intersection elements are:\n";
    for(;i<7&& j<5;)
    {
     if(a[i]==b[j])
     {
         cout<<a[i]<<"\t";
         i++;
         j++;
     }
     else if(a[i]<b[j])
     {
         i++;
     }
     else if(a[i]>b[j])
     {
         j++;
     }
    }
}
/*
// with hashmaps
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1;i++){
    int min=arr[i];
    int minIndex=i;
    for(int j=i+1;j<n;j++){
    //  if(arr[j]<min) for decreasing order. 
    if(arr[j]<min){
            min=arr[j];
            minIndex=j;
        }
    }
        int temp;
        temp=arr[i];
        arr[i]=min; // or arr[minIndex]
        arr[minIndex]=temp;
    }
}
vector<int> Array_intersection(int* a,int *b ,int size1, int size2) {
	vector<int> output;
	unordered_map<int, int> seen;
	for (int i = 0; i < size1; i++) {
		if (seen.count(a[i]) > 0) {
			continue;
		}
		seen[a[i]] = 1;
    }
     for (int i = 0; i < size2; i++)
	{
     if(seen[b[i]]==1)
     output.push_back(b[i]);
	}
	return output;
}
int main() {
	int a[] = {6,2,6,2,1,9,8};
    int b[] ={3,6,8,2,9};
    selectionSort(a,7);
    selectionSort(b,5);
	vector<int> output = Array_intersection(a,b,7,5);
    cout<<"intersection elements are:\n";
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] <<"\t";
	}
}
*/