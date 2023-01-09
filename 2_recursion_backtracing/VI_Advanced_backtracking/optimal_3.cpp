#include<iostream>
using namespace std;

int n;
int ans=0,DONE;
// rowmask denote which positions(colms) in all rows are filled
//ld,rd denotes unsafe positions along diagonals for the current row
//done is vector of all 11111(n times 1)
//safe denotes the cols which are safe in the current row
// more optimized n queen code !

void solve(int rowMask, int ld, int rd)
{
    if(rowMask==DONE)
    {
        ans++;
        return;
    }
    int safe =DONE &(~(rowMask) | ld | rd);
    while(safe)
    {
        int p=safe &(~safe);
        safe=safe -p;
        solve(rowMask |p,(ld | p)<< 1,(rd | p)>>1);
    }
}
int main()
{
    cin>>n;
    DONE=((1<<n)-1); // left shift operator if n =4 then done equals 15. 
    solve(0,0,0); // rowmask stores cols , rowmask 0 0 0 0 ld=0 0 0 0 rd = 0 0 0 0 initially
    cout<<ans<<endl;
    return 0;
}