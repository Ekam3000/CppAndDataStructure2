#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x & 1)
    {
        cout << "the number is odd";
    }
    else
        cout << "the number is even "; 
}
// or check whether 0th bit is one or zero --> if it is one then the number is odd otherwise even.. u have already written a program to check ith bit is 1 or 0 .. same apply this for 0th bit