/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int maximum;
    int smaximum;
};
void builtTree(int *arr, node * tree, int treeIndex, int start, int end)
{
    if(start==end)
    {
        tree[treeIndex].maximum = arr[start];
        tree[treeIndex].smaximum = INT_MIN;
        return;
    }
    int mid= (start+end)/2;
    builtTree(arr, tree, 2*treeIndex, start, mid);
    builtTree(arr, tree, 2*treeIndex+1, mid+1, end);
    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex+1];
    tree[treeIndex].maximum = max(left.maximum, right.maximum);
    tree[treeIndex].smaximum = min(max(left.maximum, right.smaximum), max(left.smaximum, right.maximum));
    return;
}
 int main()
 {
   int n;
   cin>>n;
   int * arr = new int[n];
   for(int i=0; i<n; i++)   
   {
    cin>>arr[i];
   }
   node *tree =new node[3*n];
   builtTree(arr,tree,1,0,n-1);
   for(int i=0;i< 3*n;i++)
   {
    cout<<tree[i].maximum <<","<<tree[i].smaximum<<endl;
   }
 }