#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<char> q;
    // map<char,int> m;
    // we can use map or more easily we can use
    int freq[27] = {0};
    char ch;
    cin >> ch;
    while (ch != '.')
    {
        int a = ch - 'a';
        freq[a]++;
        if (freq[a] == 1)
        {
            q.push(ch);
            cout << q.front();
        }
        else
        {
            while (!q.empty())
            {
                int a = q.front() - 'a';
                if (freq[a] > 1)
                {
                    q.pop();
                }
                else
                {
                    cout << q.front();
                    break;
                }
            }

            if (q.empty())
            {
                cout << "-1";
            }
        }
        cin>>ch;
    }
}
/*
aaabbcdbbaac
a-1-1b-1ccccccd
*/