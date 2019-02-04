/*
  https://www.geeksforgeeks.org/check-if-two-trees-are-mirror/
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
Node *popTree(void)
{
  Node *t =makeNode(26);
  t->l = makeNode(10);
  t->r = makeNode(3);
  t->l->l = makeNode(6);
  t->l->r = makeNode(4);
  t->r->r = makeNode(3);
  return t;
}
bool isMirror(Node *l,Node *r)
{
   if(l== NULL && r==NULL)
     return true;
   if(l==NULL || r == NULL)
     return false;
   return (l->d == r->d) && isMirror(l->l,r->r) && isMirror(l->r,r->l);
}
Node *makeMirror(Node *r)
{
  if(r==NULL)
    return NULL;
  if(r->l==NULL && r->r ==NULL)
    return r;
  swap(r->l,r->r);
  r->l = makeMirror(r->l);
  r->r = makeMirror(r->r);
  return r;
}
int main()
{
  Node *a = popTree();
  Node *b = makeMirror(popTree());
  cout<<isMirror(a,b);
  return 0;
}
