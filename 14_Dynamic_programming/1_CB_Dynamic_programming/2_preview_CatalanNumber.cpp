Problem Name: Catalan Numbers
Problem Difficulty: None
Problem Constraints: 1 <= N <= 100
Problem Description:
Print nth [Catalan Number](https://en.wikipedia.org/wiki/Catalan_number).
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14,.. .

/*Input Format: One integer n
Sample Input: 10
Output Format: Print the catalan number at position N.
Sample Output: 16796
*/
#include<bits/stdc++.h>
using namespace std; 

// A dynamic programming based function to find nth 
// Catalan number 
unsigned long int catalanDP(unsigned int n) 
{ 
    unsigned long int catalan[n+1]; 

    catalan[0] = catalan[1] = 1; 

    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 

    return catalan[n]; 
} 
int main(){
    unsigned int n;
    cin>>n;
    cout<<catalanDP(n)<<endl;
}