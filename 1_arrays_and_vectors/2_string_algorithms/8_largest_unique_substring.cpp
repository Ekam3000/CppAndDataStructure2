#include <iostream>
using namespace std;
int longest_unique_substring(char *input)
{
    int start = 0;
    int next = 0;
    int VarForLongestSubS;
    int lastindex[256]; // lastindex[256] representing when we have seen
    // a particular character last time.
    for (int i = 0; i < 256; i++)
    {
        lastindex[i] = -1;
    }
    int longestSoFar = 0;
    while (input[next] != '\0')
    {
        char nextChar = input[next];
        if (lastindex[nextChar] < start)
        {
            lastindex[nextChar] = next;
            next++;
        }
        else
        {
            int currentOptionlength = next - start;
            if (currentOptionlength > longestSoFar)
            {
                longestSoFar = currentOptionlength;
            }
            VarForLongestSubS = start;
            start = lastindex[nextChar] + 1;
            lastindex[nextChar] = next;
            next++;
        }
    }
    // for comparing last window of longest substring with previous window 
    //of longest substring and hence printing longest substring accordingly
    int currentOptionlength = next - start;
    if (currentOptionlength > longestSoFar)
    {
        longestSoFar = currentOptionlength;
        cout << "longest substring :" << endl;
        for (int i = start; i < next; i++)
        {
            cout << input[i];
        }
    }
    else
    {
        cout << "longest substring :" << endl;
        for (int i = VarForLongestSubS; i < next-1; i++)
        {
            cout << input[i];
        }
    }
    return longestSoFar;
}
int main()
{
    char input[100];
    cin >> input;
    cout << endl
         << longest_unique_substring(input) << endl;
}
// abcdabceb
// ans- dabce ans length 5
// acdbfghib
// ans- acdbfghib ans length 8
