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