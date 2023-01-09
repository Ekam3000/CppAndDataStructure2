// bitset approach
// making complexity of isSafe function O(1) time for each i,j
#include<iostream>
#include<bitset>
using namespace std;
bitset<30> col,d1,d2;
// bitset is array of bits and it is memory efficient .
//if size is 30 , the total memory it will occupy is 30 bits 
void solve(int r,int n, int &ans,int board[][20])
{// r current row 
    if(r==n)
    {
        // print the board array here 
        ans++;
        return; 
    }
    for(int c=0;c<n;c++)
    { // col[c] does not contain a queen d1[r-c +n-1] does not contain a queen d2[r+c] does not contain a queen
        if(!col[c] && !d1[r-c +n-1] && !d2[r+c])
        {
            col[c] = d1[r-c +n-1]=d2[r+c]= board[r][c]=1;
            solve(r+1,n,ans); // recursive call to next row
            col[c] = d1[r-c+n-1]=d2[r+c] =board[r][c]=0;// backtrack

        }
    }
}
int main()
{
    int n;
    cin>>n;
    int ans=0;
    int board[10][10] = {0};
    solve(0,n,ans,board);
    cout<<ans<<endl;
    return 0;

}
// new time complexity problem is 1/N(the privious complexity)