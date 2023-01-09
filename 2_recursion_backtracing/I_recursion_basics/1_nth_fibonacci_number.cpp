// more than one call of function is going to happen , in this case two calls are going to happen
#include<iostream>
using namespace std;
int nth_fibonacci(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return nth_fibonacci(n-1) + nth_fibonacci(n-2);
}
int main()
{
int n;
cin>>n;
cout<<nth_fibonacci(n);
    return 0;
}