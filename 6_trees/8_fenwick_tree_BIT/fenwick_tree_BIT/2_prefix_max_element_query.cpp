#include <bits/stdc++.h>
using namespace std;

int a[10000];
int BIT[10000] = {0};
// range sum query
void update(int i, int val, int N)
{
    while (i <= N)
    {
        BIT[i] = max(BIT[i],val) ;
        i += (i & (-i));
    }
}
// sum till the ith index
int query(int i)
{
    int ans = 0;
    while (i >= 0)
    {
        ans = max(ans,BIT[i]);
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
        update(i, a[i], n);
    }
    // query
    int q;
    cin >> q;
    while (q--)
    {
       int idx;
       cin>>idx;
       cout<<query(idx)<<endl;
    }
}