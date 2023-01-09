// subsequence can have non continuous part of the string/array.
// abc --> ab and ac are both valid subsequences.
// sub array means u need to have the continuous part of the array.

// main u have to think is whether u have to keep the element or not in the output array.
// two arrays input and output.

// keep filling the output array with subsequences.

#include <iostream>
using namespace std;
void generate_subsequence(char *input, char *output, int i, int j)
{
    if (input[i] == '\0')
    {
        output[i] = '\0';
        cout << output[i] << endl;
        return;
    }
    // include the current char
    output[j] = input[i];
    generate_subsequence(input, output, i + 1, j + 1);
    // exclude the current char
    generate_subsequence(input, output, i + 1, j);
}
int main()
{
    char input[] = "abc";
    char output[10];
    generate_subsequence(input, output, 0, 0); // 0 , 0 the current indexes for the input and output arrays
}