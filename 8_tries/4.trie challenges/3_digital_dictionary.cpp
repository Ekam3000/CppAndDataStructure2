/*
Problem Name: Digital Dictionary
Problem Difficulty: 2
Problem Constraints: 1≤N≤30000 <br>
sum(len(stringi)) ≤ 2∗10^5 <br> 
1≤Q≤10^3
Problem Description:
Peter found a digital dictionary which is far better than normal dictionaries. The digital dictionary has an input field in which one can search any string and the dictionary displays all the words whose prefix is that input string in lexicographical order. Now you are given a task to make your own digital dictionary. You will be given words that you can store in your database and then you need to design the search functionality. And if no such words are available for a given search word, add this word to your dictionary.

Input Format: Single integer N which denotes the number of words which are to be stored in the database of the dictionary. <br>
N lines of input, where in each line there is a string made up of lowercase/uppercase letter Single integer Q which denotes the number of queries. <br>
Q number of lines describing the query string on each line given by user.
Sample Input: 4
pet
peter
rat
rack
5
pe
pet
r
rac
rat
Output Format: If word with prefix exists in the database, then you need to print all the words with the given prefix in lexicographical order in separate lines else you need to print "No suggestions" without the inverted commas.
Sample Output: pet
peter
pet
peter
rack
rat
rack
rat
*/