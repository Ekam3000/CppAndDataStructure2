#include<bits/stdc++.h>
using namespace std;
#define int long long int
int poly_hash_string(string s)
{
    int p=31, m=1e9 +7;
    int p_powr=1;
    int hash=0;
    for(int i=0; i<s.size(); i++)
    {
     hash += (p_powr *(s[i]-'a'+1));
     p_powr *= p;
     p_powr %= m;
     hash %=m;
    }
    return hash;
}
// becoz of define long long int 
// int is converted int32_t
int32_t main()
{
    string s ="abababab";
    int s_hash = poly_hash_string(s);
    cout<<s_hash;
}