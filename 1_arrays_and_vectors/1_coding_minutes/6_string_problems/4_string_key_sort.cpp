/*
1.stirng tokenization strtok()
2.convert keys ito numeric
3.sorting --> lexographic conversion, numeric
4.reverse the sorted order what we have got if true
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string extractHelper(string str, int key)
{
    // taking help of strtok
    // converting data of string to char* -->string.c_str() here string is the given string and c_str() is an operator for converting string to char.
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s; // typecasting
}
int convertToInt(string s)
{ // converting string to numerical value
    int ans = 0;
    int p = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ans += (s[i] - '0') * p;
        p = p * 10;
    }
    return ans;
}
bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    return convertToInt(s1.second) < convertToInt(s2.second);
}
bool lexioCompare(pair<string, string> s1, pair<string, string> s2)
{
    return s1.second<s2.second;
}
int main()
{
    
    int n;
    cin >> n;
    cin.get();
    string a[10]; // for storing the number of strings.
    
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    int key;
    string reverse, ordering;
    cin >> key >> reverse >> ordering;

    pair<string,string> strPair[100];
    for (int i = 0; i < n; i++)
    {
        strPair[i].first = a[i];
      strPair[i].second = extractHelper(a[i], key);
    }
    // sorting
    if (ordering == "numeric")
    {
        sort(strPair, strPair + n, numericCompare);
    }
    else
        sort(strPair, strPair + n, lexioCompare);

    // reversal
    if (reverse == "true")
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(strPair[i], strPair[n - 1 - i]);
        }
    }
    // print the output
    for (int i = 0; i < n; i++)
    {
        cout << strPair[i].first<< endl;
    }
    return 0;
}
/*
3
92 022
82 12
77 13
2 false numeric
*/