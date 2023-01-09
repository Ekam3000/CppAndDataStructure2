/*
Setup time
Send Feedback
There are n students in a class. The height and weight of those students are known. A row has to be made in the morning assembly and make those students stand in the row one by one. The setup time is the time to make those students stand in a row. The setup time is given as:
(i) The setup time for the first student is 1 minute.
(ii) Right after a student of height l and weight w , the next student needs no setup time for a student of height l' and weight w' if l ≤ l' and w ≤ w'.
Otherwise, it will need 1 minute for setup.
You have to find the minimum setup time in minutes to make all those students stand in a row.
Input Format:
The first line of input has an integer n, that represents the number of students, and the second line contains 2n positive integers l1 , w1 , l2 , w2 ,..., ln , wn, where li and wi are the height and weight of the i th student respectively.
Output Format:
The output should contain the minimum setup time in minutes
Constraints:
 1 <= n <= 5000 
 1<=li,wi<=10000
Sample Input:
3 
2 2 1 1 2 2
Sample Output:
1
*/