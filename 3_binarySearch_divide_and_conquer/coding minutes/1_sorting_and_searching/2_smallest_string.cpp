// output the lexicographicallyy smallest concatenation of srtings
#include<bits/stdc++.h>
using namespace std;
bool compare(string x, string y)
{
    return x+y<y+x;
}
int main()
{
    string arr[]={"a","ab","aba"};
    int n=3;
    sort(arr,arr+n,compare);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i];
    }
    return 0;
}