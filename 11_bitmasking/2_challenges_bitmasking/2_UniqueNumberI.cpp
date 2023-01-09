/*
Problem Name: Unique Number - I
Problem Difficulty: None
Problem Constraints: n < 10^5
Problem Description:
We are given an array containg n numbers. All the numbers are present twice except for one number which is only present once. Find the unique number without taking any extra spaces and in linear time. ( Hint - Use Bitwise )

Input Format: First line contains the number n. Second line contains n space separated number.
Sample Input: 7
1 1 2 2 3 3 4 
Output Format: Output a single line containing the unique number
Sample Output: 4



=====Solution=====
*/
#include<iostream>
int main() {
    int t;
    std::cin >> t;
    
    int result = 0;
    while(t--){
        int n;
        std::cin >> n;
        result^=n;
    }
    std::cout << result << std::endl;
	return 0;
}

