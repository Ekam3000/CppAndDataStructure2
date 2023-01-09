#include<bits/stdc++.h>
using namespace std;
// recursive code
int countSub(string a, string b, int m, int n)
{
    // base case
    if((m==-1 and n==-1 )or n==-1)
    {
        return 1;
    }
    if(m==-1)

    {
        return 0;
    }
    if(a[m]==b[n])
    {
        return countSub(a,b,m-1,n-1) + countSub(a,b,m-1,n);
    }
    return countSub(a,b,m-1,n);
}

int main()
{
    string a ="ABCECDG";
    string b="ABC";
    cout<<countSub(a,b,a.length()-1,b.length()-1)<<endl;

}