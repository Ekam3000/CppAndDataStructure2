// We are given an array containing n numbers . All the numbers are present twice except for two numbers which are present only once . find the unique numbers in linear time without using any extra space 
// example a =[1,1,2,3,5,2,5,7]
// unique =3, 7
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[100005];
    int no;
    int res=0;
    for(int i=0; i<n;i++)
    {
        cin>>no;
        a[i]=no;
        res=res^no;
    }
    //res =a^b;
    int temp= res;
    int pos =0;
    while((temp&1)!=1)
    {
     pos++;
     temp=temp>>1;
    }
    // the first bit in res is at position pos
    int mask =(1<<pos);
    // find those numbers which contain set bit at position pos;
    int x=0;
    int y=0;
    for(int i=0;i<n;i++)
    {
        if((a[i] &mask)>0)
        {
            x=x^a[i];
        }
    }
    y=res^x;
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
}