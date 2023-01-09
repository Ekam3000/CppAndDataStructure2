#include<iostream>
using namespace std;
int power_function(int n, int power)
{
if(power==0)
{
    return 1;
}
int subans= power_function(n,power/2);
int SubansSq=subans*subans;
if(power&1) // power is odd
{
    return n*SubansSq;
}
else
return SubansSq;
}
int main()
{
    int n;
    cin>>n;
    int power;
    cin>>power;
    cout<<power_function(n,power);
    return 0;
}