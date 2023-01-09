#include<iostream>
using namespace std;

int storing_occurences(int *array,int *store,int ele,int i,int n,int j)
{
if (n==0)
{
    return j;
}
    if(array[0]==ele)
    {
        store[j]=i;
        j++;
    }
    storing_occurences(array+1,store,ele,i+1,n-1,j);
}
void all_occurences(int arr[],int n, int key,int i)
{
if (n==0)
{
    return;
}
    if(arr[0]==key)
    {
    cout<<i<<" ";
    }
    all_occurences(arr+1,n-1,key,i+1);
}
int main()
{
    int array[5] = {3, 4, 3, 6, 3};
    int ele = 3;
    int i=0;
    all_occurences(array, 5, ele,i);
    cout<<endl;
    int store[5];
    int k=storing_occurences(array,store,ele,i,5,0);
    cout<<"number of occurences "<<k<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<store[i]<<" ";
    }
}