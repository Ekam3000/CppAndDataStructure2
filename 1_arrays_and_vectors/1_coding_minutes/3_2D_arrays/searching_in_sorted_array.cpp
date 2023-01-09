//1. brute force O(n*m) , two for loops if element finds print
// 2. binary search on every row
// 3. traversing one row and one column O(n+m). pickup one corner from which moving in one direction increases the value and moving in other direction decreases the value. so u will ultimately reaches the target.algo known as staircase algo.
#include<iostream>
using namespace std;
pair<int, int> staircaseSearch(int arr[][4], int n, int m, int key)
{
    if(key <arr[0][0] or key> arr[n-1][m-1])
    {
        return {-1,-1};
    }
    int i=0;
    int j=m-1;
    while(i<=n-1 &&j>=0)
    {
        if(arr[i][j]==key)
        {
            return {i,j};
        }
        else if(arr[i][j]>=key)
        {
            j--;
        }
        else{
            i++;
        }
    }
    return {-1,-1};
}
int main()
{
    int array[][10]={{1,2,3,4},{5,6,7,8},{9,10,11,12 },{13,14,15,16}};
    int n=4,m=4;
    int key;
    cin>>key;
   pair<int,int> coord= staircaseSearch(array,n,m,key);
   cout<<coord.first<<" "<<coord.second<<endl;
    return 0;

}
