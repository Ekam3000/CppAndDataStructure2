#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x;
    int y;
    Point()
    {
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
class Compare
{
    public:
    bool operator()(const Point& a, const Point& b) 
    {
        if(a.x==b.x)
        {
            return a.y<b.y;
        }
         return a.x<b.x;
    }
};
// count rectangles function
int count_rectangles(vector<Point> points)
{
    // 1. Insert all points in the set
    set<Point, Compare> s;
    for (Point p : points)
    {
        s.insert(p);
    }
    int ans=0;
    // 2. logic Brute force two points + lookup for other two
    for (auto it = s.begin(); it != prev(s.end()); it++)
    {
        for (auto jt = next(it); jt != s.end(); jt++)
        {
            Point p1 = *it;
            Point p2 = *jt;

            // small check that we want to make
            if (p2.x == p1.x or p2.y == p1.y)
            {
                continue;
            }

            // P3,p4
            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);
            // Lookup
            if (s.find(p3) != s.end() and s.find(p4) != s.end())
            {
                ans += 1;
            }
        }
    }
    return ans/2;
}
int main()
{
    int N;
    cin >> N;
    int x, y;
    vector<Point> points;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }
    cout << count_rectangles(points) << endl;
}