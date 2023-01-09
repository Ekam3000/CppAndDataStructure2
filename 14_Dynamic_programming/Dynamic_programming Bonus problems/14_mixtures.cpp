/*
Mixtures
Send Feedback
Hermione is attending the Magic Potion's Class in Hogwarts . She has N potions in front of her lying in a row . Her task is to combine these potions into 1 . In order to do so she can pick any two adjacent potions of color A,B and mix them to form another potion of color C=(A+B)%100 which will then replace A and B in the row (Two potions combine to form one potion) . But when a new potion is formed it produces smoke of value A*B . Hermione needs your help to minimise the smoke produced in the above task .
Input Format :
Line 1 : Integer N 
Line 2 : A list of N integers, representing colors of each potion
Output Format :
Minimum Smoke that can be produced
Constraints :
1<= N <=100
0 <= color of a potion <= 99
Sample Input :
3
1 2 4
Sample Output :
14
*/