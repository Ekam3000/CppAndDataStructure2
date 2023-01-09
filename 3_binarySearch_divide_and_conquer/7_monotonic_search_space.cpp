// one technique
 // search space .. (will be sorted and monotonic)
 // here in this problem we are not given any sorted array
 // most of the problems will can be solved using binary search, will have this concept of monotonic search space 
#include<iostream>
using namespace std;
float square_root(int n, int p)
{
    int s=0;
    int e=n;
    int mid;
    float ans=-1;
    while(s<=e)
    {
         mid=(s+e)>>1;

        if(mid*mid==n)
        {
            return mid;
        }
         if(mid*mid>=n)
        {
            e=mid-1;
        }
        else
        {
            ans=mid; // this ans is our one of the expected ans ,, and will be updated whenever calls
            s=mid+1;
        }
    }
    // floating point 
    // brute force
    // linear search for each place (for floating part)
     float inc=0.1;
     for(int times=1;times<=p;times++)
     {
        // do linear search
        while(ans*ans<=n)
        {
            ans=ans+inc;
        }
        // overshot the value
        ans=ans-inc;
        inc=inc/10;
     }
    return ans;
}
/*first linear_search    second linear_search
3.0 inc=0.1              3.10   inc=0.01
3.1                      3.11
3.2                      3.12     
3.3                      3.13
 |                        |
 |                        |
*/
int main()
{
    int n;
    cin>>n;
    cout<<square_root(n,3)<<endl;
    return 0;
}