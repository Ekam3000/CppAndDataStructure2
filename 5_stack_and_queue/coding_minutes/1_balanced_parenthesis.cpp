#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string input)
{
    stack<int> s;
    for(auto i : input)
    {
        if(s.empty() || i=='(' || i=='{' || i=='[')
        {
            s.push(i);
        }
        else if(!s.empty() && s.top() =='[' && i==']')
        {
            s.pop();
        }
        else if(!s.empty() && s.top() =='{' && i=='}')
        {
            s.pop();
        }
        else if(!s.empty() && s.top() =='(' && i==')')
        {
            s.pop();
        }
        else if(i>='a' || i<='z')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
   if(s.empty())
   {
    return true;
   }
   else
   {
    return false;
   }
}

int main() 
{
    string s ="((a+b+c)+[d])";
    if(isBalanced(s))
    {
        cout<<"balanced";
    }
    else
    {
        cout<<"not balanced";
    }
}
