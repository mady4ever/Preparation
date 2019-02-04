/*
  https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
  
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
Node *popTree(void)
{
  Node *t = makeNode(5);
  t->l = makeNode(3);
  t->r = makeNode(8);
  t->l->r = makeNode(2);
  t->r->l = makeNode(1);
  //        5
  //     3    8
  //      2  1
  //
  return t;
}
int sumTree(Node *r)
{
   if(r==NULL) return 0;
   if(r->l==NULL && r->r == NULL)
     return r->d;
   int r_d = r->d; //old value.
   int ll = sumTree(r->l);
   int rr = sumTree(r->r);
   r->d = ll+rr + r_d;
   return r->d;
}
void InOrder(Node *r)
{
  if(r)
  {
     InOrder(r->l);
     cout<<r->d<<"\t";
     InOrder(r->r);
  }
}
int main()
{
  Node *t = popTree();
  InOrder(t);
  cout<<endl;
  sumTree(t);
  InOrder(t); 
  return 0;
}
