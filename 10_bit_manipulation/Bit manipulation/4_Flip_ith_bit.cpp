

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int x, y, i;
    cin >> x;
    cout << "enter ith bit to check:\n";
    cin >> i;
    y = pow(2, i); // or y= 1<<i;
     int z = x ^ y;
     cout<<"\n"<<z;
     
}