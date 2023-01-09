/*
Palindromic Substrings
Send Feedback
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/
#include <bits/stdc++.h>
using namespace std;
int palindromicSubstring(char input[])
{
    int count = 0;
    int len = strlen(input);
    // odd length
    for (int i = 0; input[i] != '\0'; i++)
    {
        int mid = i;
        int left = i - 1, right = i + 1;
        count++; // for single length substrings
        while (left >= 0 && right < len)
        {
            if (input[left] == input[right])
            {
                count++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
    }
    // even length
    for (int i = 0; i < len - 1; i++)
    {
        int mid1 = i;
        int mid2 = i + 1;
        if (input[mid1] != input[mid2])
        {
            continue;
        }
        int left = mid1 - 1, right = mid2 + 1;
        count++;
        while (left >= 0 && right < len)
        {
            if (input[left] == input[right])
            {
                count++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}
int main()
{
    char input[100];
    cin >> input;
    cout << palindromicSubstring(input) << endl;
}