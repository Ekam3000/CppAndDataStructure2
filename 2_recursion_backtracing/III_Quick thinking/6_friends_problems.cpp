// given N,friends who want to go to a party on bikes . each guy can go as single or as a couple. find the number of ways in which N friends can go the party 

#include<iostream>
using namespace std;
int NO_of_ways(int n){
    if(n==1 || n==0)
    {
        return 1;
    }
     if(n==2)
    {
        return 2;
    }
    int c=NO_of_ways(n-1)+(n-1)*NO_of_ways(n-2); // the multiplication of n-1 says that each guy can go as couple , so a guy selecting another guy from a grp of (n-1) friends.
    return c;
}
int main(){
    int friends;
    cin>> friends;
    cout<<NO_of_ways(friends);
}