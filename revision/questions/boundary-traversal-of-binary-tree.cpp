/*
   1] print root 
   2] print left side of r->l in top down manner.
   3] print leaf nodes of r->l
   4] print leaf of nodes r->r;
   5] print r->r in bottom up mannder.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *l,*r;
}Node;
Node * makeNode(int d)
{
   Node *t= (Node *)malloc(sizeof(Node));
   t->d = d;
   t->l = t->r = NULL;
   return t;
}
Node *insert(Node *r,int d)
{
  if(r==NULL)
    return makeNode(d);
  if(d < r->d)
    r->l = insert(r->l,d);
  else
    r->r = insert(r->r,d);
  return r;
}
Node *popTree(void)
{
  Node *t = insert(NULL,5);
  t = insert(t,3);
  t = insert(t,8);
  t = insert(t,2);
  t = insert(t,9);
  return t;
}
void leaf(Node *r)
{
  if(r==NULL)
    return;
  if(r->l==NULL && r->r==NULL)
   cout<<r->d<<"\t";
  leaf(r->l);
  leaf(r->r);
}
void leftSide(Node *r)
{
  if(r==NULL) 
    return;
  if(r->l)
  {
     cout<<r->d<<"\t";
     leftSide(r->l);
  }
  if(r->r)
  {
    cout<<r->d<<"\t";
    leftSide(r->r);
  }
}
void righSide(Node *r)
{
   if(r==NULL)
     return;
   if(r->r)
   {
     righSide(r->r);
     cout<<r->d<<"\t";
   }
   if(r->l)
   {
     righSide(r->l);
     cout<<r->d<<"\t";
   }
}
void printOuter(Node *r)
{
  if(r)
  {
    cout<<r->d<<"\t";
    leftSide(r->l);
    leaf(r->l);
    leaf(r->r);
    righSide(r->r);
  }
}
int main()
{
   Node *t = popTree();
   printOuter(t);
   return 0;
}
