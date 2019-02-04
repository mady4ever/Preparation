/*
  https://www.geeksforgeeks.org/print-nodes-dont-sibling-binary-tree/
  sublings means: not have two childrens or have only one child or leaf nodes.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
   int d;
   Node *l,*r;
}Node;
Node *makeNode(int d)
{
   Node *t = (Node *)malloc(sizeof(Node));
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
void printWithoutsublings(Node *r)
{
   if(r==NULL)
    return;
   if(r->l==NULL && r->r==NULL)
     cout<<r->d<<"\t";
   else if(r->l==NULL && r->r!=NULL)
     cout<<r->d<<"\t";
   else if(r->l!=NULL && r->r == NULL)
     cout<<r->d<<"\t";
   printWithoutsublings(r->l);
   printWithoutsublings(r->r);
}
int main()
{
   Node *t = popTree();
   printWithoutsublings(t);
   return 0;
}
