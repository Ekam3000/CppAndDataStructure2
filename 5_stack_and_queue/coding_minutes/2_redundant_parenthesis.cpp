// redundant parenthesis or not
// ((a+b))    yes
// (a+(b)/c)  yes
//(a+b*(c-d)) No

// opening closing bracket ka combination tabhi aaye ga if in b/w brackets u get an operator


#include<bits/stdc++.h>
using namespace std;
bool Not_redundant(string s1)
{
stack<int> s;
for (int i=0;i<s1.length();i++)
{
    if(s.empty() || s1[i] ==')' || (s1[i]>='a' && s1[i]<='z') || s1[i]=='-' || s1[i]=='+' || s1[i]=='*' || s1[i]=='/') 
    // or simply
  //  if(s[i] !=')')
    {
        s.push(s1[i]);
    }
    else if( !s.empty() && s1[i] == ')')
    {
        int flag=1;
        while(s.top() !='(')
        {
            if(s.top()=='-' || s.top()=='+' || s.top()=='*' || s.top()=='/')
            {
                flag=0;
            }
            s.pop();
        }
        s.pop();
        if(flag==1)
        {
            return false;
        }
    }
   return true;
}
}

int main()
{

string str;
//str="((a+b)+c)"
str= "((a+b)+c) +(d*e)";
if(Not_redundant(str))
{
 cout<<"no redundency";
}
else{
    cout<<"contains redundant parenthesis";
}
return 0;
}