#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x; // if a number is power of 2 .. then it will only contain one single bit as 1 rest all others are zero
    if (x & x-1)
    {
        cout << "the number is not a power of 2";
    }
    else
        cout << "the number is a power of 2 "; 
}