/*
 https://www.geeksforgeeks.org/add-greater-values-every-node-given-bst/
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
   int d;
   Node *l, *r;
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
   if(d <= r->d)
    r->l = insert(r->l,d);
   else
    r->r = insert(r->r,d);
   return r;
}
Node *popTree1(void)
{
  Node *t = makeNode(5);
  t->l = makeNode(3);
  t->r = makeNode(9);
  t->l->r = makeNode(6);
  return t;
}
Node *popTree(void)
{
  Node *t = insert(NULL,5);
  t = insert(t,2);
  t = insert(t,8);
  t = insert(t,7);
  t = insert(t,3);
  t = insert(t,4);
  t = insert(t,9);
  t = insert(t,6);
  return t; 
}
void inOrder(Node *t)
{
  if(t)
  {
    inOrder(t->l);
    cout<<t->d<<"\t";
    inOrder(t->r);
  }
}
bool isBST(Node *r,int min,int max)
{
   if(r==NULL)
     return true;
   if(r->d < min || r->d > max)
     return false;
   return isBST(r->l,min,r->d) && isBST(r->r,r->d,max);
}
bool isBSTInOrder(Node *r,int &pre)
{
  //bool ll=false;
  //bool rr=false;
  if(r==NULL) return true;
  isBSTInOrder(r->l,pre);
  if(pre && pre > r->d)
  {
     return false;
  }
  pre = r->d;      
  isBSTInOrder(r->r,pre);
  //return ll && rr;
}
void addGreaterToAllValues(Node *r,int &pre)
{
  if(r)
  {
     addGreaterToAllValues(r->r,pre);
     r->d +=pre;
     pre = r->d;
     addGreaterToAllValues(r->l,pre);
  }
}
int main()
{
   Node *t = popTree();
   //inOrder(t);
   //cout<<isBST(t,INT_MIN,INT_MAX);
   int pre=0;
   //cout<<isBSTInOrder(t,pre);
   inOrder(t);
   addGreaterToAllValues(t,pre);
   cout<<endl;
   inOrder(t); 
}
