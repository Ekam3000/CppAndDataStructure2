/*@csalgo

Problem Name: Unique Numbers - II
Problem Difficulty: None
Problem Constraints: n < 10^5
Problem Description:
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format: First line contains the number n. Second line contains n space separated number.
Sample Input: 4
3 1 2 1
Output Format: Output a single line containing the unique numbers separated by space
Sample Output: 2 3



=====Solution=====
*/
#include<iostream>
int main() {
    
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int mask=0;
    for (int i = 0; i < n; i++) {
        mask^=a[i];
    }
    int result=mask;
    int count=0;
    if(!(mask&1)){
        count++;
        mask>>=1;
    }
    mask = 1;
    while(count--){
        mask<<=1;
    }
    
    int num1 =0;
    int num2 = 0;
    for (int i = 0; i < n; i++) {
        if((a[i]&mask)!=0){
            num1^=a[i];
        }
    }
    num2=result^num1;
    
    if(num1<num2){
        std::cout << num1<<" "<<num2 << std::endl;
    }else{
        std::cout << num2<<" "<<num1 << std::endl; 
    }

	return 0;
}

