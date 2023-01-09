/*
Problem Name: Treasure Hunt
Problem Difficulty: 3
Problem Constraints: 1 <= N <= 10^5
Sum of all length of all strings is greater than 1 and lesser than 10^6.
Problem Description:
The pirates are on a hunt to the biggest treasure chase of the millenium. The found ‘N’ clues each consisting of a string in each clue. Let the N strings be - a1,a2,a3 ...... an. To find the code of the treasure box they need to find the sum of total number of combination (i, j) [the combination are unordered] such that - length of longest common prefix of (ai, aj) = M. They need to do this for all k that lies in [0, max(length(ai))].

Input Format: First line of the test case will be the number of strings N . 
Then N lines follows. On each line you will find a string.
Sample Input: 3
ab 
abc 
m

Output Format: The output contains an single integer denoting the sum of all the number combinations that can be produced
Sample Output: 3

*/