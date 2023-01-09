#include<bits/stdc++.h>
using namespace std;
void builtTree(int * arr, int start, int end,int * tree, int treeNode)
{
 if(start==end)
 {
    tree[treeNode] = arr[start];
    return;
 }
 int mid=(start+end)/2;
 builtTree(arr,start, mid,tree, 2*treeNode);
 builtTree(arr,mid+1,end, tree,2*treeNode+1);
 tree[treeNode]= min(tree[2*treeNode] ,tree[2*treeNode+1]);
 return;
}
int query(int * tree, int start, int end, int qs, int qe, int index)
{
    // completely outside given range
    if(qs> end ||qe< start)
    {
        return INT_MAX;
    }
    // completely inside given range
    if(start>= qs ||end <= qe)
    {
        return tree[index];
    }
    // partially inside and partially outside
    int mid= (start+end)/2;
    int ans1= query(tree,start ,mid, qs,qe,2*index);
    int ans2= query(tree,mid+1,end, qs,qe,2*index +1);

    return min(ans1,ans2);
}
void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    // out of bounds
    if(l> se || r<ss)
    {
        return;
    }
    // leaf node
    if(ss==se) 
    {
        tree[index] +=inc;
        return;
    }

    // recursive case
    int mid=(ss+se)/2;
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index]= min(tree[2*index], tree[2*index+1]);
    return ;
}

void updateNode(int * tree, int ss, int se, int i, int increment, int index)
{
    if(i> se || i< ss)
    {
        return;
    }
    // leaf node
    if(ss==se)
    {
        tree[index] += increment;
        return;
    }
    // otherwise
     int mid=(ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index]= min(tree[2*index], tree[2*index+1]);

}
int main()
{
int a[]={1,3,2,-5,6,4};
int n= sizeof(a) / sizeof(a[0]);
int * tree = new int[4*n+1];
builtTree(a,0,n-1,tree,1);
// lets also print the array
for(int i=1;i<=13;i++)
{
    cout<<tree[i]<<" ";
}
//updateNode(tree,0,n-1,3,+10,1);
updateRange(tree,0,n-1,3,5,+10,1);

int q;
cin>>q;
while(q--)
{
    int l,r;
    cin>> l>>r;
    cout<<query(tree,0,n-1,l,r,1)<<endl;
}
}