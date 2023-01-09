/*
Fishmonger
Send Feedback
A fishmonger wants to bring his goods from port to the market. On his route, he has to traverse an area with many tiny city states. Of course he has to pay a toll at each border.
Because he is a good business man, he wants to choose the route in such a way that he has to pay as little money for tolls as possible. On the other hand, he has to be at the market within a certain time, otherwise his fish start to smell.
Given n number of states and the time t in which he has to reach the market. You need to find and print the minimum toll amount that he has to pay in order to reach the market in given time. The first state is the port and last one is the market.
Input Format :
Line 1 : Two integers, n and t
Next n lines : n numbers, specifying for each state the travel time to the i-th state.      
This table is terminated with an empty line. The table of the tolls follows in the same format
Output Format :
Print in one line the total amount of tolls
Constraints :
3 <= n <= 100
1 <= t <= 1000
Sample Input :
4 7
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0
Sample Output :
6
*/