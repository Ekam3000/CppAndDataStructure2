/*
Problem Name: Playing With Bits
Problem Difficulty: 1
Problem Constraints: Q,a,b are integers.
Problem Description:
Prateek Bhayia likes to play with bits. One day Prateek bhayia decides to assign a task to his student Sanya. You have help Sanya to complete this task. Task is as follows - Prateek Bhayia gives Q queries each query containing two integers a and b. Your task is to count the no of set-bits in for all numbers between a and b (both inclusive) 

Input Format: Read Q - No of Queries, Followed by Q lines containing 2 integers a and b.
Sample Input: 2
1 1
10 15
Output Format: Q lines, each containing an output for your query.
Sample Output: 1
17



=====Solution=====
*/
#include <iostream>
using namespace std;

int countBits(int num)
{
	int cnt = 0;

	while(num)
	{
		cnt += (num & 1);
		num >>= 1;
	}
	return cnt;
}

int main()
{
	int testCases;
	cin >> testCases;

	while(testCases--)
	{
        int a,b,total;
        
        cin >> a >> b;
        
        total = 0;
        
        for(int i = a ; i <= b ; i++)
        {
            total += countBits(i);
        }
        
        cout << total << "\n" ;
	}

	return 0;
}