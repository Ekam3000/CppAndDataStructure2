#include <iostream>
using namespace std;
void generate_strings(char *in, char *out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // first digit
    int k = in[i] - '0';
    char c = k + 'A' - 1;
    out[j] = c;
    generate_strings(in, out, i + 1, j + 1); // agar first digit par recursion call kar diya
    if (in[i + 1] != '\0')                   // agar second digit ko bhi sath lekar aana ho
    {
        int b = in[i + 1] - '0';
        int no = k * 10 + b;
        if (no <= 26)
        {
            c = no + 'A' - 1;
            out[j] = c; // if 1234 is the input then 12 is the number and L is the alphabet so L placed at out[0]
            generate_strings(in, out, i + 2, j + 1);
        }
    }
    return;
}
int main()
{
    char a[100];
    cin >> a;
    char out[100];
    generate_strings(a, out, 0, 0);
}
/*
given 1-A
2-B
3-C
4-D
...
...
*/


/*
answer 
1 2 3 4 -> A B C D
(12)3 4 -> LCD
1(23) 4 -> AWD
*/


/*
1234
ABCD
AWD
LCD
*/