#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
// also done polygon question from codeforces
const int N = 100005;

struct point
{
    int x, y;
    bool operator<(point &O)
    {
        if (O.x == x)
        {
            return y < O.y;
        }
        else
        {
            return x < O.x;
        }
    }
    bool operator==( point & O)
    {
        return (x==O.x && y==O.y);
    }
};

bool cw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
bool ccw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool collinear(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}
void convex_hull(vector<point> &p)
{
    if (p.size() <= 2)
    {
        return;
    }
    sort(p.begin(), p.end());
    // now p[0] is p1, p[n-1] is p2
    int i, n = p.size();
    point p1 = p[0], p2 = p[n - 1];
    // actually p1 is bottom left point and p2 is top right point
    vector<point> up, down;
    up.pb(p1);
    down.pb(p1);
    for (i = 1; i < n; i++)
    {
        // now i have to check whether my current point is in lower half or upper half
        if (i == n - 1 || !ccw(p1, p[i], p2))
        {
            // p[i] is in the upper half
            while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i]))
            {
                up.pop_back();
            }
            up.pb(p[i]);
        }
        if (i == n - 1 || !cw(p1, p[i], p2))
        {
            // p[i] is in the lower half
            while (down.size() >= 2 && cw(up[up.size() - 2], down[down.size() - 1], p[i]))
            {
                down.pop_back();
            }
            down.pb(p[i]);
        }
    }
    // up and down vector contains all points including the points p1 and p2 repeated
    p.clear();
    for(i=0; i<up.size(); i++)
    {
         p.pb(up[i]);
    }
    for(i=0; i<down.size(); i++)
    {
         p.pb(down[i]);
    }
    // p vector contains all the points fron up as well as down 
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end())-p.begin());
}
void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<point> p(n);
    for (i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    map<pair<int, int>,int> mp;
    cin>>m;
    for(i=0;i<m;i++)
    {
        point temp;
        cin>> temp.x >> temp.y;
        mp[{temp.x, temp.y}]++;
        p.pb(temp);
    }
    convex_hull(p);
    // now p contains all the points of convex hull
   for(auto x:p) 
    {
       // cout<<x.x<<" "<<x.y<<'\n';
       if(mp.count({x.x,x.y}))
       {
        cout<<"NO";
        return;
       }
    }
    
}

int32_t main()
{
    solve();
    return 0;
}