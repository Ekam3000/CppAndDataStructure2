#include<iostream>
using namespace std;
int Multiplying(int a, int b)
{
if(b==0)
return 0;
int c =Multiplying(a,b-1);
c +=a;
return c;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<Multiplying(a,b);
    return 0;
}