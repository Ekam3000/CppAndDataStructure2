//count binary strings of length N, which have NO consecutive ones.
// binary string - combination of 0 and 1.
// input N -> number of digits 
#include<iostream>
using namespace std;
int NO_of_ways(int n){
    if(n==1)
    {
        return 1;
    }
     if(n==2)
    {
        return 3;
    }
    int c=NO_of_ways(n-1)+NO_of_ways(n-2);// second digit 0 se hi fill hoge agar first digit 1 se fill hue 
    return c;
}
int main(){
    int N;
       cin>> N;
    cout<<NO_of_ways(N);
}