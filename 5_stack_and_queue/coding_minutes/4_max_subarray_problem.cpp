// max subarray in every window of size k
/*
N=9;
arr[]={1,2,3,1,4,5,2,3,6}
k=3;
output-> 3 3 4 5 5 5 6
*/
// we willuse deque
// deque will only contaians the useful elements
// two types of elements that are not useful
// elements which are in the window and are smaller than the current element to be placed ..that elements will be removed
//element to be removed if it is out of the window 
// instead of storing the element in the deque , we will store the index , becoz it will help me to find out whether an element is out of the window or not
#include<bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int>& a, int k)
{  
    deque<int> Q(k);
    //1. process only the first k elements
    for(int i=0;i<k;i++)
    {
        while(!Q.empty() && a[i]>=a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);// becoz we dont know whether this element is to be useful or not 
    }
    //2. remaining the elements of the array
    for(;i<n;i++)
    {
        cout<<a[Q.front()]<<" ";
        // contraction of the deque , remove element from the left when an index lies outside the current window
        while(!Q.empty() and Q.front()<=i-k) // i index to i-k index is the window that we are taking from the array everytime
        {
            Q.pop_front();
        }
         while(!Q.empty() && a[i]>=a[Q.back()])
        {
            Q.pop_back();
        }
        // always push back
        Q.push_back(i);
    }
}
int main()
{
vector<int> arr{1,2,3,1,4,5,2,3,5};
int k=3;
maxSubArray(arr,k);
}
