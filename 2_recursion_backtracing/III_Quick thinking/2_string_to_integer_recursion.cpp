//Use Integer. parseInt() to Convert a String to an Integer. This method returns the string as a primitive type int. ...
#include<iostream>
using namespace std;
int  string_to_integer(string a,int & b)
{
if(a.empty())
{
    return b;
}
char s=a[0];
b = b*10 + (s-'0');
string_to_integer(a.substr(1),b);
}
int main()
{
    string a="1234";
   // string a[]="1234"; this  cannot be done
    int b=0;
    string_to_integer(a,b);
    cout<<b;
    return 0;
}