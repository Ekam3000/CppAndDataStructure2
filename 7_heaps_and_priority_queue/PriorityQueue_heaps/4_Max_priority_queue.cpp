/*Code : Max Priority Queue
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.
*/

// convert this c language code to c++ and u are done with ur code
#include<stdio.h>
void Insert(int A[], int n)
{
    int i=n, temp;
    temp=A[i];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int Delete(int A[], int n)
{
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val; // the element that i have deleted , can be placed at the last position of array(which is no longer remain as a part of the heap)
    i=1;j=i*2;
    while(j<n-1) // j<n-1 , j can reach the value upto last node of the heap ..i.e (n-1 , index. ek element to delete ho gya ,is liye n-1 element bache ab)
    {
        if(A[j+1]>A[j])
        j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
        break;
    }
    return val;
}
int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    // elements formed after the heap is formed
    // 40,25,35,10,5,20,30
    int i;
    //loop wise insersion
    for(i=2;i<=7;i++)
    {
    Insert(H,i);
    }
    // individual insersion
    /*
    Insert(H,2);
    Insert(H,3);
    Insert(H,4);
    Insert(H,5);
    */
   // loop wise deletion --->heap sort
   for(i=7;i>1;i--)
   {
        Delete(H,i);
   }
   // individual deletion
   /*
   printf("Deleted value is %d\n",Delete(H,7));
   printf("Deleted value is %d\n",Delete(H,6));
   */
   for(i=1;i<=7;i++)
    {
    printf("%d",H[i]);
    printf("\n");

    }
    return 0;

}