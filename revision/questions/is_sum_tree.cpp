/*
  check if given tree is sum tree or not.
  https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
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
int getSum(Node *r)
{
   if(r==NULL)
     return 0;
   if(r->l == NULL && r->r == NULL)
     return r->d;
   return r->d + getSum(r->l) + getSum(r->r);
}
bool isSumTree(Node *r)
{
   if(r==NULL)
     return true;
   if(r->d == getSum(r->l) + getSum(r->r))
    return true;
   return isSumTree(r->l) && isSumTree(r->r);
}
bool isSumTreeOptimized(Node *r)
{
   int ll=0;
   int rr=0;
   if(r==NULL)
     return true;
   if(r->l==NULL && r->r == NULL)
     return true;
   if(isSumTreeOptimized(r->l) && isSumTreeOptimized(r->r))
   {
      if(r->l==NULL) // if it's a leaf node.
        ll=0;
      else if (r->l->l==NULL && r->l->r == NULL) // if it's left child is leaf node.
        ll = r->l->d;
      else      // else r->d = 2 * left side nodes value.
        ll = 2 * r->l->d;
     
      if(r->r == NULL)
        rr = 0;
      else if (r->r->l == NULL && r->r->r == NULL)
        rr = r->r->d;
      else 
        rr = 2*r->r->d;
      return (r->d == ll+rr);
   }
   return false;
}
int main()
{
  Node *t =makeNode(26);
  t->l = makeNode(10);
  t->r = makeNode(3);
  t->l->l = makeNode(6);
  t->l->r = makeNode(4);
  t->r->r = makeNode(3);
  cout<<isSumTree(t); //O(n^2) solution.
  cout<<endl<<isSumTreeOptimized(t);
  return 0;
}
