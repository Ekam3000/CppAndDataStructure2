#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
struct Node *root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
int count(struct Node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1; //  this procedure is working in postorder form ( first left childs are counted , then right child are counted , then this root(current node))
    return 0;
}
/*
int count(Node *p)
{
    int x,y;
    if(p!= NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        //1 ->
        if(p->lchild && p->rchild)
        return x+y+1; 
        // line 60 and 61 is used for counting number of nodes with degree two.
        
        // 2 ->
        //  return x+y + p->data;
        // this is doing sum of all nodes 
        else
        return x+y;
    }
    return 0;
}
*/
/* 2)
 // so u can also change the condition to count number of leaf nodes.
int count(Node *p)
{
    int x,y;
    if(p!= NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        //1 ->
        if(p->lchild ==NULL && p->rchild==NULL)
        return x+y+1; 
        else
        return x+y;
    }
    return 0;
}
*/
/*
number of nodes with degree 1.
 if((p->lchild != NULL && p->rchild==NULL) ||( p->lchild==NULL && p->rchild != NULL))
 or
 if(p->lchild != NULL ^ p->rchild!=NULL) // ^ symbol is known as exclusive OR
*/
/*
 deg 1 or 2
 if( p->lchild || p->rchild)
 */
int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    Treecreate();
    printf(“% d”, count(root));
    printf(“% d”, height(root));
    return 0;
}
/*
    8
   / \
  3   5
 /   / \
12  10  6
  \    /
   4  2
  / \
 9   7
*/