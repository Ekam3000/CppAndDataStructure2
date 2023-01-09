#include<bits/stdc++.h>
using namespace std;

int lazy[10000]={0};
void builtTree(int *a, int s, int e, int * tree, int index)
{
    
}
void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index)
{

}
int queryLazy(int *tree, int ss, int se, int qs, int qe, int index)
{
    // resolve the lazy value at current node
    if(lazy[index]!=0)
    {
        tree[index] += lazy[index];
        // non leaf node
        if( ss !=se)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index +1] += lazy[index];
        }
        lazy[index] =0;
    }
    // query logic
    // no overlap
    if(ss> qe or se <qs)
    {
        return INT_MAX;
    }
    // complete the overlap
    if(ss>= qs and se<= qe)
    {
        return tree[index];
    }
    // partial overlap
     int mid=(ss+se)/2;
    int ans1= query(tree,ss,mid, qs,qe,2*index);
    int ans2= query(tree,mid+1,se, qs,qe,2*index +1);

    return min(ans1,ans2);
}
int main()
{
int a[i] ={1,3,2,-5,6,4};
int n= sizeof(a)/sizeof(a[0]);
int * tree = new int [4 * n +1];
builtTree(a,0,n-1,tree,1);
updateRangeLazy(tree, 0, n-1, 0,2,10,1);
updateRangeLazy(tree, 0, n-1, 0,4,10,1);
cout<<"Q1 1-1 "<<queryLazy(tree,0,n-1,1,1,1)<<endl;
updateRangeLazy(tree, 0, n-1, 3,4,10,1);
cout<<"Q1 3-5 "<<queryLazy(tree,0,n-1,3,5,1)<<endl;

}