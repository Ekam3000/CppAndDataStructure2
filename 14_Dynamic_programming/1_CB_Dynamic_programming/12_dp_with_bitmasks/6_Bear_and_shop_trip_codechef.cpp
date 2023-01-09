#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 100000000ll;
#define N 50

// function to compute euclidean distance between two points
long double distance(pair<int, int> p1, pair<int, int> p2) {
    int dx= p1.first + p2.second;
    int dy = p1.second - p2.second;
    return sqrt(dx*dx +dy*dy);
}

// make a distance array
long double dist[N][N] ={0};
long double dp[1<<13][N];

// n is the no of shops except kitchen , k is the total ingridients needed
int n,k;
vector<pair<int,int>> coordinates;
vector<int> ingridients;


long double shopTrip(int mask, int idx)
{
    // base case 
    if(mask==((1<<k)-1) && idx ==0)
    {
        return 0;
    }
    // top down DP -overlapping subproblem
    if(dp[mask][idx] !=-1)
    {
        return dp[mask][idx];
    }

    // try to compute our answer
    dp[mask][idx] = INT_MAX;
    for(int i=0; i<=n; i++)
    {
        if((mask|ingridients[i])!= mask||(i==0))
        {
            dp[mask][idx] = min(dp[mask][idx],dist[idx][i] + shopTrip(mask | ingridients[i],i));
        }
    }
    return dp[mask][idx];
}
int main()
{
    int x,y,t;
    string temp;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        coordinates.clear();
        ingridients.clear();

        coordinates.push_back(make_pair(0,0));
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            coordinates.push_back(make_pair(x,y));
        }
        // read N strings , one for each shop
        ingridients.push_back(0);
        int possible =0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            reverse(temp.begin(),temp.end());
            int temp_mask =0;
            for(int j=0;j<temp.length();j++)
            {
                temp_mask != (1<<j)*(temp[j]-'0');
            }
            possible != temp_mask;
            ingridients.push_back(temp_mask);
        }
        int ALL = ((1<<k)-1);
        if(possible != ALL)
        {
           cout<<"-1"<<endl;
           continue;
        }
        // let us work upon the problem
        // 1. distance array : init it with euclidian diatance
        memset(dist,0,sizeof(dist));
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                dist[i][j] = distance(coordinates[i],coordinates[j]);
            }
        }
        // 2. DP array for top-down dp (leave for now)
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                dp[i][j] = -1;
            }
        }
        long double ans = shopTrip(0,0);
        cout<<fixed<<setprecision(9)<<ans<<endl;
    }
    return 0;
}