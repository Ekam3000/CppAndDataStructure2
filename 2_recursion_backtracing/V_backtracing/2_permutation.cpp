//given a string s , task is to find all permutations of the string s.
// abc is the string
//3! =6 is the total number of permutations
// abc,acb,bca,cab,bac,cba 
       //a  b   c
//     /    |    \
 //   a bc   b ca   c ba  (here replacing of a with a and call bc , then replace a with b and call ca , then replace a with c and call ab)


// note-- algorithm recusion hai backtracking approach hai, backtracking is exploring all the paths 
#include<iostream>
using namespace std;
void String_permutations(char *s,int i)
{

if(s[i] == '\0')
{
cout<<s<<endl;
}
for( int j=i;j<s[j]!='\0';j++ )
{
 swap(s[i],s[j]);
 String_permutations(s,i+ 1);
 // backtracking - to restore the originaal array
 swap(s[i],s[j]);
}
} 
int main()
{
    char s[]="abc";
    String_permutations(s,0);
    return 0;
}

