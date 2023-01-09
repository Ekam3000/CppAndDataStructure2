/*
Problem Name: XOR Profit Problem
Problem Difficulty: 2
Problem Constraints: l <= r <= 1000
Problem Description:
We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Input Format: We are given two integers x and y
Sample Input: 5
6
Output Format: Print the maximum value of a XOR b
Sample Output: 3



=====Solution=====
*/
#include <cstdio>
#include <algorithm>
using namespace std;
    
int l, r, a, b, ret;
    
int main () {
    scanf("%d %d", &l, &r);
    for(a = l; a <= r; a++)
        for(b = a; b <= r; b++)
            ret = max(ret, a ^ b);
    printf("%d\n", ret);
    return 0;
}
//O(n ^ 2)

