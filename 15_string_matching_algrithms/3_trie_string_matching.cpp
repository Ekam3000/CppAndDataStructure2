#include<bits/stdc++.h>
using namespace std;
int main()
{
    string text ="abaacadbacad";
    string pat ="aaca";
    int n =text.size();
    int m=pat.size();
    // O(n)
    for(int i=0;i+4<=n;i++)
    {
        if(text.substr(i,m)==pat)
        {
            cout<<"yes found at index"<<i;
            return 0;
        }
    }
    // O(n^m)
    cout<<"Not found";
}