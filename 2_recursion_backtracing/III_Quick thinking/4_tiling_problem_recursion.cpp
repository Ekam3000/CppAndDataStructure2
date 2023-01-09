/* given a wall of size of 4XN,and tiles of size(1,4) and (4,1). in how many ways you can build the wall ?
*/
#include<iostream>
using namespace std;
int NO_of_ways(int n){
    if(n<=3 && n>0)
    {
        return 1;
    }
     if(n==4)
    {
        return 2;
    }
    int c=NO_of_ways(n-1) +NO_of_ways(n-4); // number of ways if we put one  (4,1) size brick firstly+ number of ways if we put 4  (1,4) size bricks firstly  
    return c;
}
int main(){
    int breadth;
    cin>> breadth;
    cout<<NO_of_ways(breadth);
}