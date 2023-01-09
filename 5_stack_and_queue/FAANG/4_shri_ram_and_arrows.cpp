// 10
// 1 -1 2 -5 7 -6 -5 3 -5 10
// collision occurs b/w 1 and -1, in stack point of view 1 (s.top()>0) and -1 moves downwards and 1 moves upwardshaving equals and opposite mag so cancel out each other.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, -1, 2, -5, 7, -6, -5, 3, -5, 10};
    stack<int> s;
    for (int i = 0;i<v.size();i++)
    {
        if (s.top() > 0 and v[i] < 0 && !s.empty())
        {
            if ((v[i] + s.top()) == 0)
            {
                s.pop();
            }
            else if ((v[i] + s.top()) < 0)
            {
                s.pop();
                s.push(v[i]);
            }
            else if ((v[i] + s.top()) > 0)
            {
                continue;
            }
        }
        else
        {
         s.push(v[i]);
        }
    }
    stack<int> s1;
    while (!s.empty())
    {
        s1.push(s.top());
        s.pop();
    }
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}