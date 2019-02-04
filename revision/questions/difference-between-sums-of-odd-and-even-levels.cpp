/*
  https://www.geeksforgeeks.org/difference-between-sums-of-odd-and-even-levels/
  r->d - (left + right) 
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
int height(Node *r)
{
   if(r==NULL) return 0;
   return max(height(r->l),height(r->r)) + 1;
}
int diameter(Node *r)
{
   if(r==NULL) return 0;
   int ll =height(r->l);
   int rr =height(r->r);
   return max(ll+rr+1, max(diameter(r->l),diameter(r->r)));
}
int diameter_optimized(Node *r,int &h)
{
  int lh=0;
  int rh=0;
  int ld=0;
  int rd=0;
  if(r==NULL)
  {
    h=0;
    return 0;
  }
  ld = diameter_optimized(r->l,lh);
  rd = diameter_optimized(r->r,rh);
  h = max(lh,rh) + 1;
  return max(lh+rh+1,max(ld,rd));
}
int odd_even_level_diff(Node *r)
{
   if(r==NULL) return 0;
   return r->d - (odd_even_level_diff(r->l) + odd_even_level_diff(r->r)); 
}
int main()
{
  Node *t = popTree();
  //cout<<diameter(t);
  //int h=0;
  //cout<<endl;
  //cout<<diameter_optimized(t,h);
  cout<<odd_even_level_diff(t);
  return 0;
}
