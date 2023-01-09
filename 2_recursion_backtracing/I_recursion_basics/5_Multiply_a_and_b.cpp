#include<iostream>
using namespace std;
int multiply(int a, int b)
{
    if(b==0)
    {
        return 0;
    }
    if(b==1)
    {
        return a;
    }
    return  a + multiply(a,b-1);
}
int main()
{
    int a;
    int b;
    cin>>a>>b;
    cout<<multiply(a,b);
    return 0;
}