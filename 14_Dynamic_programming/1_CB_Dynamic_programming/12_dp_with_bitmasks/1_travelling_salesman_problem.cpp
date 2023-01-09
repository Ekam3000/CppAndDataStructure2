#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 9999999
int n =4;
//adj matrix which defines the graph
int dist[10][10] ={{0,20,42,25},{20,0,30,34},{42,30,0,10},{25,34,10,0}};
int VISITED_ALL =(1<<n) -1;
int tsp(int mask, int pos)
{
  if(mask ==VISITED_ALL)
  {
    return dist[pos][0];
  }
  int ans = INT_MAX;
  // try to goto an unvisited city
  for(int city =0;city<n;city++)
  {
    if((mask&(1<<city))==0)
    {
        int newAns = dist[pos][city] + tsp(mask|(1<<city),city);
        ans = min(ans,newAns);
    }
  }
return ans;

}
int main()
{
cout<<tsp(1,0)<<endl;
return 0;
}