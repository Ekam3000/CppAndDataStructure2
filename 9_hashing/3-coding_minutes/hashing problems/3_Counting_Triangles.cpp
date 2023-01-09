#include<bits/stdc++.h>
using namespace std;

int count_triangles(vector<pair<int, int> >& points)
{
unordered_map<int, int> freq_x;
unordered_map<int, int> freq_y;
// count the freq by iterating over all the poiints
for(auto p:points)
{
    int x= p.first;
    int y= p.second;
    freq_x[x]++;
    freq_y[y]++;

}

int count =0;
for(auto p:points)
{
    int x=p.first;
    int y=p.second;

    int fx= freq_x[x];
    int fy= freq_y[y];
    if(fx>=1 and fy>=1)
    {
        count += (fx -1) * (fy -1);
    }
    return count;
}
}


int main()
{
int N;
cin>>N;
vector<pair<int, int>> points;
for(int i=0; i<N;i++)
{
    int x,y;
    cin>>x>>y;
    points.push_back({x,y});
}
cout<<count_triangles(points);
}