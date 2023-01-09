#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={110,11,9,40,40,40,50,100};
    int n=sizeof(arr)/sizeof(int);
    // to search an element in an sorted array
    // we can use find function , but if the array is sorted one , then we can binary search , its complexity is O(n).
    int key;
    cout<<"enter key for search:";
    cin>>key;
    bool present =binary_search(arr, arr+n,key);
    if(present)
    cout<<"present";
    else
    cout<<"absent";

    // to get the index
    //the algorithm function provides us two funs() for this lower_bound(s,e,key) and upper_bound()
    
    auto lb =lower_bound(arr,arr+n,40);// lower bound will return the address  of first occurence of the element this is >=40
    // in lower_bound function consecutive array values starting from index 0 are compared with given key value
    cout<<endl<<"lower bound:"<<(lb-arr); // index 3

    // upper bound --> will return the address of the first occurence of the element that is >40.
    auto up=upper_bound(arr,arr+n,40);
    cout<<endl<<"upper bound:"<<(up-arr); // index 6

    // what if the element is not present, in that case upeer bound and lower bound of the given  number will be same:
    // example element is 41 : lb of 41 is 6 (50) as lb definition is >=40 and up is >40

    // upper bound can be used to calculate the freq of a given number in an array.
    // in this case upper_bound of 40 is 6, and we have also calculated the lower_bound of 40 ->3.
    // so freg of 40 is up-bl -> 6-3 = 3.
    cout<<endl<<"freq. of given number 40:"<<up-lb;
}


