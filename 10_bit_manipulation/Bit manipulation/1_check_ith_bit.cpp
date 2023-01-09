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
    if (x & y)
    {
        cout << "ith bit is 1";
    }
    else
        cout << "ith bit is 0";
    
     
}