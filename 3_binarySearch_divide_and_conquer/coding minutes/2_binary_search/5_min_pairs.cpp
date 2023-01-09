// given two non-empty arrzays, find the pair of numbers(one from each array) whose diff is minimum. print the any one pair with the smallest diff.
// sample input ->
// a1=[-1,5,10,20,3]
//a2[26,134,135,15,17]
// can we apply binary search ? no , no directly
// first we should sort the array (one of the array)
// apply lower_bound binary search on other array for min diff
// complexity -> O(MlogN + NlogM)

#include<bits/stdc++.h>
using namespace std;
/*
void lower_bound(vector<int>& v, int n)
{
   int s=0;
   int e= v.size()-1;
   int ans=-1;
   while(s<=e)
   {
    int mid=(s+e)/2;   
    if(v[mid]==n)
    {
        ans=mid;
        e=mid-1;
    }
    else if(v[mid]>n)
    {
        e=mid-1;
    }
    else
    {
        s=mid+1;
    }
   }
   return ans;
}
*/
void min_pair(vector<int>& a, vector<int>& b)
{
    sort(b.begin(), b.end());
     int p1,p2;
       int diff=INT_MAX;
    for(int i=0;i<a.size();i++)
    {
       // lower_bound(b,a[i]);
       // or simply call lower_bound of stl
      
       auto lb=lower_bound(b.begin(),b.end() ,a[i])-b.begin();
       if(lb>=1 and (a[i]-b[lb-1])<diff)
       {
        diff=a[i]-b[lb-1];
        p1=a[i];
        p2=b[lb-1];
       }
       // greater / right
       if(lb !=b.size() and b[lb]-a[i]<diff)
       {
        diff=b[lb]-a[i];
        p1=a[i];
        p2=b[lb];
       }
    }
    cout<<"min_pair"<<p1<<" "<<p2<<endl;
}
int main()
{
    vector<int> a1={-1,5,10,20,3};
    vector<int> a2={26,134,135,15,17};
    min_pair(a1,a2);
    return 0;

}