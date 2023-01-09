/*
Problem Name: Incredible Hulk
Problem Difficulty: None
Problem Constraints: 1 <= T <= 10 <br>1 <= N <= 10^5

Problem Description:
The Planet Earth is under a threat from the aliens of the outer space and the Marvel Avengers team is busy fighting against them.
Meanwhile, The Incredible Hulk has to defeat an enemy who is N steps above the level where he is standing (assume it as the 0th level). Hulk, because of his incredible jumping ability can take jumps in power of 2. In order to defeat the enemy as quickly as possible he has to reach the Nth step in minimum moves possible. 
Help Hulk to find the same and contribute in saving the Mother Earth.

<img src="https://image.flaticon.com/icons/svg/1487/1487240.svg" width="200px">


Input Format: The first line contains the number of test cases T. T test cases follow:
The first line of each test case contains a number N. 

Sample Input: 3
3
4
5

Output Format: Output T lines, containing the minimum number of moves required by Hulk to reach the Nth step
Sample Output: 2
1
2




=====Solution=====
*/
#include <iostream>
using namespace std;
long long convertDecimalToBinary(unsigned long long int);
int main ()
{
    unsigned long long int n;
    cin >> n;
    unsigned long long int arr[n], i;

    for (i = 1; i <= n; i++)
        cin >> arr[i-1];

    for (i = 0; i < n; i++)
    {
        unsigned long long int binaryNumber, sum = 0;
        binaryNumber = convertDecimalToBinary(arr[i]);

        while (binaryNumber != 0)
        {
            unsigned long long int t;
            t = binaryNumber%2;
            sum = sum + t;
            binaryNumber = binaryNumber/10;
        }
        cout << sum << endl;
    }
    return 0;
}
long long convertDecimalToBinary(unsigned long long int n)
{
    long long binaryNumber = 0;
    unsigned long long int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}
