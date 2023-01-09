#include<bits/stdc++.h>
using namespace std;

void builtTree(int * arr, int * tree, int start, int end, int treeNode)
{
 if(start==end)
 {
    tree[treeNode] = arr[start];
    return;
 }
 int mid=(start+end)/2;
 builtTree(arr, tree,start, mid, 2*treeNode);
 builtTree(arr, tree,mid+1,end, 2*treeNode+1);
 tree[treeNode]= tree[2*treeNode] + tree[2*treeNode+1];
}
void updateTree(int * arr, int * tree, int start, int end, int treeNode, int idx, int value)
{
if(start==end)
{
    arr[idx] = value;
    tree[treeNode] = value;
    return;
}
int mid= (start+end)/2;
if(idx>mid)
{
    updateTree(arr, tree, mid+1, end, 2*treeNode+1,idx, value);
}
else{
   updateTree(arr, tree,start, mid,2*treeNode,idx, value); 
}
tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}
int main()
{
    int arr[]={1,2,3,4,5};
    int *tree = new int[10];
    builtTree(arr,tree,0,4,1);
    for(int i=1; i<10; i++)
    {
        cout<<tree[i]<<endl;
    }
    updateTree(arr,tree,0,4,1,2,10);
}