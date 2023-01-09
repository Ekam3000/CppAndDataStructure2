/*
Play a Game
Send Feedback
Anjali has N positive integers and she has to play a game using them. The rules of the games are as follows:
1. If all the numbers are equal, the game ends.
2. If not, then follow these steps:
(i) Select two unequal numbers.
(ii) Subtract the smaller one from the larger one.
(iii) Replace the larger one with the subtraction result obtained above.
She knows that game will always terminate on the same value, no matter how she plays the game. You have to tell if the game terminates on 1.
You have to tell Anjali the number of sub-sequences of the given number sequence, for which, playing the above game on the subsequence will terminate on 1. A sub-sequence can be obtained from the original sequence by deleting 0 or more integers from the original sequence.
Input Format:
The first line of input contains the value of N(the length of the given sequence).
The second line of input contains N positive integers separated by space.
Output Format:
The output contains a single integer denoting the total number of subsequences from the given sequence which results in ending the game with all 1.
Constraints:
1<=N<=60
1<= Value of an integer <=10 4
Sample Input:
4
3 4 8 16
Sample Output:
7
Explanation:
Subsequences are:
{ 3,  4 }
{ 3,  8 }
{ 3, 16 }
{ 3, 4, 8 }
{ 3, 4, 16 }
{ 3, 8, 16 }
{ 3, 4, 8, 16 }
*/