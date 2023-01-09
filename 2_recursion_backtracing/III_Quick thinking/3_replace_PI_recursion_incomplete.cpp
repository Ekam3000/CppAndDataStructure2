/* replace pi with 3.14
xpighpilmpipi ->x3.14gh3.14lm3.143.14*/
// incomplete.
#include <iostream>
#include <string.h>
using namespace std;
void ReplacePi(char a[])
{
    if (a[0] == '\0' or a[1] == '\0')
    {
        return;
    }
    if (a[0] == 'p' && a[1] == 'i')
    {
        int l = 2;
        while(a[l]!='\0')
        {
            l++;
        }
        while(l>=2)
        {
              a[l+2] = a[l];
              l--;
        }
        a[0] = '3';
        a[1] = '.';
        a[2] = '1';
        a[3] = '4';
         ReplacePi(a + 4);
    }
    else
    {
         ReplacePi(a + 1); 
    }
   return;
}
int main()
{
    char a[100] = "xpighpilmpipi";
    ReplacePi(a);
    for (int i = 0; a[i] != '\0'; i++)
    {
        cout << a[i];
    }
    return 0;
}