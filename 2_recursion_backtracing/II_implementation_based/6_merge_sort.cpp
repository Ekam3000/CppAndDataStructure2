#include<iostream>
using namespace std;

void merge(int a[],int si,int ei)
{
int size= ei-si+1;
int mid= (si+ei)/2;
int *out= new int[size];
int i=si;
int j=mid+1;
int k=0;
while(i<=mid &&j<=ei){
    if(a[i]>=a[j]){
        out[k++]=a[j++];
    }
    else{
        out[k++]=a[i++];
    }
}
while(i<=mid){
    out[k++]=a[i++];
}
while(j<=ei){
    out[k++]=a[j++];
}
int l=0;
for(int i = si;i<=ei;i++){
    a[i]=out[l++];
}
delete []out;    
}
void mergesort(int array[], int p,int r)
{
    if(p>=r)
    {
    return;
    }
    int q=(p+r)/2;
    mergesort(array,p,q);
    mergesort(array,q+1,r);
    merge(array,p,r);
}

int main()
{
    int array[10];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int p=0;
    int r=n-1;
    mergesort(array,p,r);
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}