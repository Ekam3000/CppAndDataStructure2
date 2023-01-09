// ladder problem.

#include<iostream>
using namespace std;
int NO_of_ways(int n){
    if(n==1)
    {
        return 1;
    }
     if(n==2)
    {
        return 2;
    }
    if(n==3)
    {
        return 4;
    }
    int c=NO_of_ways(n-1)+NO_of_ways(n-2)+NO_of_ways(n-3);
    return c;
}
int main(){
    int steps;
    cin>>steps;
    cout<<NO_of_ways(steps);
}