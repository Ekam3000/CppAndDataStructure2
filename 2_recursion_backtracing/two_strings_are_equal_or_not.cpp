#include<iostream>
#include<string.h>
using namespace std;
bool equal_or_not( string s1, string s2)
{
    if(s1.length()%2!=0 || s2.length()%2!=0)
    {
        return false;
    }
    if(s1==s2)
    {
        return true;
    }
    string a1=s1.substr(0, s1.length()/2-1);
    string b1=s1.substr( s1.length()/2,s1.length()-1);
    string a2=s2.substr(0, s2.length()/2-1);
    string b2=s2.substr( s2.length()/2 ,s2.length()-1);
    return (equal_or_not(a1,a2) && equal_or_not(b1,b2)) || (equal_or_not(a1,b2) &&equal_or_not(a2,b1));
}
int main()
{
     int n;
    cin >> n;
    cin.get();// the enter that we press after entering no. of strings while giving input, will not be counted as string.
    string s[2]; // for storing the number of strings.
    for (int i = 0; i < 2; i++)
    {
        getline(cin, s[i]);
    } 
    cout<<equal_or_not(s[0],s[1]);
    return 0;
}