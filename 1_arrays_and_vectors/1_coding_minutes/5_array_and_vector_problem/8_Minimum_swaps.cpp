#include<bits/stdc++.h>
using namespace std;
int countMinSwaps(vector<int> arr)
{
// know the actual positions of elements (sorting) 
// store the current indices
int n= arr.size();
pair<int, int> ap[n];
for(int i=0; i<n; i++)
{
    ap[i].first =arr[i];
    ap[i].second =i;
}
    int ans=0;
    // sorting
    sort(ap,ap+n);

    // built the main logic 
    vector<bool> visited (n , false);

    for(int i=0; i<n;i++)
    {
        // if element is visited or element is in right position 
        int old_position = ap[i].second;
        if(visited[i]==true or old_position==i)
        {
            continue;
        }
    
    // visiting the element (index) for first time
    int node =i;
    int cycle =0;
    
    while(!visited[node])
    {
        visited[node] = true;
        int next_node =ap[node].second;
        node =next_node;
        cycle +=1;
    }
    ans +=(cycle -1);
    }
    return ans;
}
 int main()
 {
   vector<int> arr{5,4,3,2,1};
   cout<<countMinSwaps(arr)<<endl;
 }