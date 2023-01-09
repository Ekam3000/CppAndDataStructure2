// 2 -> number of pinters
//2 ->number of boards
//1 10 -> representing the length of each board
// output the minimum time required to paint the board
#include<iostream>
using namespace std;
bool max_time(int * len_of_boards , int n, int mid, int m)
{
    int count=1;
    int max_time=0;
    for(int i=0; i<n; i++)
    {
     if((max_time+len_of_boards[i])<=mid)
     {
     max_time +=len_of_boards[i];
     }
     else{
        count++;

            if (len_of_boards[i] > mid || count > m)
            {
                return false;
            }
        max_time=0;
        i--;
     }
    }
    if(count==m)
    return true;
    else
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;//number of boards, number of painters 
    int len_of_boards[n];
    for(int i=0;i<n;i++)
    {
        cin>>len_of_boards[i];
    }//10 20 30 40
    int s=0;
    s=40;// s=40 more true becoz student will be reading atleast one book and will read 40 pages.
    int e=0;
    for(int i=0;i<n;i++)
    {
        e+=len_of_boards[i];
    }
    int ans=-1;
    int mid;
    while(s<=e)
    {

        mid=(s+e)/2;
        bool c= max_time(len_of_boards,n,mid,m);
        if(c)
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// galt ans