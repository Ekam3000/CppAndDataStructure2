// given a sorted array of strings that is interspersed with empty strings, write a method to find the location of a given string
//{"ai","","","bat","","","car","cat","","","dog",""};
//bat
// output 4
#include<bits/stdc++.h>
using namespace std;
int sparse_search(string a[],int n, string key)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        int mid_left=mid-1;
        int mid_right=mid+1;
        if(a[mid]=="")
        {
            // update our mid to point to a nearest non empty string
            while(1)
            {
                if(mid_left<s and mid_right>e)
                {
                    return -1;
                }
                else if(mid_left>=s and a[mid_left]==!"")
                {
                    mid=mid_left;
                    break;
                }
                else if(mid_right<=e and a[mid_right]==!"")
                {
                    mid=mid_right;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        }
        else if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int main()
{
    string s1[]={"ai","","","bat","","","car","cat","","","dog",""};
    int n=sizeof(s1)/sizeof(s1[0]);
    string s;
    cin>>s;
    cout<< sparse_search(s1,n,s)<<endl;
    return 0;
}
//error maari jaa raha hai code