#include <iostream>
#include <stdio.h>
#include "Queue.h"
using namespace std;
class Tree
{
    Node *root;
public:
    Tree() { root = NULL; }
    void CreateTree();
    void Preorder() { Preorder(root); }
    void Preorder(Node *p);
    void Postorder() { Postorder(root); }
    void Postorder(Node *p);
    void Inorder() { Inorder(root); }
    void Inorder(Node *p);
    void Levelorder() { Levelorder(root); }
    void Levelorder(Node *p);
    int Height() { return Height(root); }
    int Height(Node *root);
};
void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    printf("Enter root value ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Tree::Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}
void Tree::Levelorder(struct Node *root)
{
    Queue q(100); 

    printf("%d ", root->data);
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}
int Tree::Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder ";
    t.Preorder();
    cout << endl;
    cout << "Inorder ";
    t.Inorder();
    cout << endl
         << endl;
    return 0;
}

/* if Node* root is declared as public in the class then Postorder,Inorder,Preorder can be called in the main function by just passing root to the Postorder,Inorder,Preorder during function calling also no need of dummy functions needed like 
void Preorder() { Preorder(root); } 
void Postorder() { Postorder(root); } 
void Inorder() { Inorder(root); } 
 etc.. 
 and the code looks like this
/*
class Tree
{
    public:
    Node *root;
Tree() { root = NULL; }
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
};
int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder ";
    t.Preorder(t.root);
    cout << endl;
    cout << "Inorder ";
    t.Inorder(t.root);
    cout << endl
         << endl;
    return 0;
    
}
*/

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