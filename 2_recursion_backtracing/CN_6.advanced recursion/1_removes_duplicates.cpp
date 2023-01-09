#include <iostream>
using namespace std;

void removes_duplicates(char *a)
{
    if (a[0] == '\0')
    {
        return;
    }
    if (a[0] != a[1])
    {
        removes_duplicates(a + 1);
    }
    else
    {
        while (a[0] == a[1])
        { 
            int i=1;
            for (; a[i] != '\0'; i++)
            {
                a[i - 1] = a[i];
            }
            a[i - 1] = a[i];
        }
        removes_duplicates(a + 1);
    }
}

int main()
{
    char a[] = "aabbbcdda";
    removes_duplicates(a);
    cout << a;
}