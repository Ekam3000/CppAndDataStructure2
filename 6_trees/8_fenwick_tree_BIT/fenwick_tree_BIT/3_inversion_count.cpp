#include <bits/stdc++.h>
using namespace std;

int a[10000];
int BIT[10000] = {0};
// range sum query
void update(int i, int val, int N)
{
    while (i <= N)
    {
        BIT[i] += val ;
        i += (i & (-i));
    }
}
// sum till the ith index
int query(int i)
{
    int ans = 0;
    while (i >= 0)
    {
        ans +=BIT[i];
        i -= (i & (-i));
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // inversion count
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        ans +=query(a[i]-1);
        update(a[i],1,n);
    }
    cout<<ans<<endl;
    return 0;
}