#include<bits/stdc++.h>
using namespace std;
int lcs (string s1, string s2, int i , int j)
{
    // base case 
    if(i==s1.length() or j==s2.length())
    {
        return 0;
    }
    // rec case
    if(s1[i]==s2[i])
    {
        return 1 + lcs(s1,s2,i+1,j+1);
    }
    int op1 = lcs(s1,s2,i+1,j);
    int op2 = lcs(s1,s2,i,j+1);
    return max(op1,op2);
}
 int main()
 {
string s1 ="ABCD";
string s2 ="ABEDG";
int n1 = s1.length();
int n2 = s2.length();
vector<vector<int> > dp(n1,vector<int>(n2));

cout<<lcs(s1,s2,0,0);
 }
 // incomplete
