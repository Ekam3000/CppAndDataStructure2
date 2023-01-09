#include<iostream>
using namespace std;
int power_function(int n, int power)
{
if(power==0)
{
    return 1;
}
int Subans=power_function(n,power-1);
Subans *=n;
return Subans;
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