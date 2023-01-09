#include <bits/stdc++.h>
using namespace std;
bool isOdd(int n)
{
    return (n & 1);
}
int getBit(int n, int i)
{
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}
int setBit(int &n, int i)
{
    int mask = (1 << i);
    int ans = n | mask;
    return ans;
}

void clearBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}
void updateBit(int &n, int i, int v)
{
    int mask = ~(1 << i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i);
}

int clearLastIBits(int n, int i)
{
int mask =(-1 <<i);
return n & mask;
}
int clearRangeItoJ(int n, int i, int j)
{
    int ones =(~0);
    int a=ones<<(j+1);
    int b=(1<<i) -1;
    int mask = a|b;
    int ans =n &mask;
    return ans;
}
int main()
{
    int n = 31;
    int i=1; // from position i to zero
   int  j=3;
   // cout<<clearLastIBits(n,i)<<endl;
   cout<<clearRangeItoJ(n,i,j)<<endl;
    //cout<<(~0)<<endl; // output -1
    /*
    cin>>i;
    clearBit(n,i);
    cout<<n<<endl;
    */

    // update the 4th bit in 5
    /*updateBit(n, 2, 0);
    updateBit(n, 3, 1);
    cout << n << endl;
    */
    /*
        cout<<getBit(n,i)<<endl;
        n=setBit(n,i);
        cout<<"ans "<<n<<endl;
    */
        // cout<<isOdd(n)<<endl;
        
}