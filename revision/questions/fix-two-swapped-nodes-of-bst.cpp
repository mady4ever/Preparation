/*
  https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
   int d;
   Node *l,*r;
}Node;
Node *makeNode(int d)
{
  Node *t=(Node *)malloc(sizeof(Node));
  if(t)
  {
    t->d = d;
    t->l = t->r = NULL;
    return t;
  }
  return NULL;
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
  t = insert(t,7);
  t = insert(t,2);
  t = insert(t,4);
  t = insert(t,8);
  t = insert(t,6);
  swap(t->d , t->l->l->d);
  return t;
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
void NodeSwaps(Node *r, Node **a, Node **m, Node **b, Node **pre)
{
  if(r)
  {
    NodeSwaps(r->l,a,m,b,pre);
    //cout<<r->d<<"\t";
    if(*pre != NULL && (*pre)->d > r->d)
    {
      if(*a!=NULL)
      {
        *a = *pre;
        *m = r;
        //cout<<a->d<<"\t"<<m->d<<endl;
      }
      else
        *b = r;
    }
    *pre = r;
    NodeSwaps(r->r,a,m,b,pre); 
  }
}
void NodeSwaps2(Node *r, Node **a,Node **b,Node *pre)
{
   if(r)
   {
       NodeSwaps2(r->l,a,b,pre);
       if(pre!=NULL && pre->d >= r->d)
       {
         if(*a==NULL)
         {
           *a = pre;
           cout<<(*a)->d<<endl;
         }
         else
         { 
           *b = pre; 
           cout<<(*b)->d<<endl;
         }
       }
       pre = r;
       NodeSwaps2(r->r,a,b,pre);
   }
}
int main()
{
  Node *t = popTree();
  Node *a=NULL,*b=NULL,*pre=NULL,*m=NULL;
  InOrder(t);
  //NodeSwaps(t,&a,&m,&b,&pre);
  //if(a && b)
  //   cout<<a->d<<"\t"<<b->d<<endl;
  //else if(a && m)
  //   cout<<a->d<<"\t"<<m->d<<endl;
  //else
  //   cout<<"Not found";
  cout<<endl;
  NodeSwaps2(t,&a,&b,pre);
  if(a && b)
    cout<<a->d<<"\t"<<b->d<<endl;
  return 0; 
}
