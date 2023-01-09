// if we want to generate permutations of abb then we will be end up with redundent/ duplicate permutations
// i want unique permutation and and i want permutation in a lexographic order.

// becoz set store unique elemnts.
#include<bits/stdc++.h>
using namespace std;
void String_permutations(char *s,int i, set<string> &S)
{

if(s[i] == '\0')
{
    string t(s);
    S.insert(t);
}
for( int j=i;j<s[j]!='\0';j++ )
{
 swap(s[i],s[j]);
 String_permutations(s,i+ 1,S);
 // backtracking - to restore the originaal array
 swap(s[i],s[j]);
}
} 
int main()
{
    char s[]="abb";
    set<string> S;
    String_permutations(s,0,S);
    for( auto s: S )
    {
        cout<<s<<" "<<endl; 
    }
    // number of unique strings 3!/2! 
    return 0;
}

