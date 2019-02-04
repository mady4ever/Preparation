/*
Transform a BST to greater sum tree
Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *l,*r;
}Node;
Node * makeNode(int d)
{
   Node *t = (Node *)malloc(sizeof(Node));
   if(t)
   {
     t->d = d;
     t->l = t->r = NULL;
     return t;
   }
   return NULL;
}
Node* popTree(void)
{
   Node *t = makeNode(0);
   t->l = makeNode(1);
   t->r = makeNode(2);
   return t;
}
void inOrder(Node *r)
{
   if(r==NULL)
     return;
   inOrder(r->l);
   cout<<r->d<<"\t";
   inOrder(r->r);
}
void preOrder(Node *r)
{
   if(r==NULL)
     return;
   cout<<r->d<<"\t";
   preOrder(r->l);
   preOrder(r->r);
}
void postOrder(Node *r)
{
   if(r==NULL)
     return;
   postOrder(r->l);
   postOrder(r->r);
   cout<<r->d<<"\t";
}
void delTree(Node *r)
{
   if(r==NULL)
    return;
   if(r->l == NULL && r->r == NULL)
   {
      free(r);
      r = NULL;
      return;
   }
   delTree(r->l);
   delTree(r->r);
}
void levelOrder(Node *r)
{
   if(r==NULL)
     return;
   queue<Node *> q;
   q.push(r);
   while(!q.empty())
   {
     Node *t = q.front();
     q.pop();
     if(t==NULL)
       continue;
     cout<<t->d<<"\t";
     if(t->l !=NULL)
       q.push(t->l);
     if(t->r != NULL);
       q.push(t->r);
   }
}
Node *insert(Node *r, int d)
{
   if(r==NULL)
     return makeNode(d);
   if(r->d > d)
      r->l = insert(r->l,d);
   else
      r->r = insert(r->r,d);
   return r;
}
bool search(Node *r, int d)
{
   if(r==NULL)
     return false;
   if(r->d == d )
     return true;
   if(r->d > d)
     return search(r->l,d);
   else 
     return search(r->r,d);
}
Node* popBST(void)
{
  Node *t = NULL;
  t = insert(t,4);
  t = insert(t,2);
  t = insert(t,1);
  t = insert(t,6);
  t = insert(t,8);
  return t;
}
Node *minNode(Node *t)
{
   Node *c = t;
   while(c->l!=NULL)
     c = c->l;
   return c;
}
Node *deletebst(Node *r, int d)
{
   if(r==NULL) return r;
   if(r->d > d)
     r->l = deletebst(r->l,d);
   else if( r->d < d)
     r->r = deletebst(r->r,d);
   else // nodes values is equal to the deleting value.
   {  
      //is leaf node.
      if(r->l == NULL && r->r == NULL)
      {
         free(r);
         r = NULL;
      }
      else //it's a non leaf node.
      {
         if( r->l == NULL) // right child present.
         {  
            Node *t = r->r;
            free(r);
            return t;            
         }
         else if(r->r == NULL)
         {
            Node *t = r->l;
            //r->d = t->d;
            free(r);
            return t; 
         }
         else // has both the childrens.
         {
             Node *t = minNode(r->r);
             r->d = t->d;
             r->r = deletebst(r->r,t->d);
         }
      }
   }
   return r;
}
void greate_sum_tree(Node *r, int &sum)
{
  if(r)
  {
    greate_sum_tree(r->r,sum);
    int t = r->d;
    r->d += sum;
    sum += t;
    greate_sum_tree(r->l,sum);
  }
}
int main()
{
  Node *t = popBST();
  //t = insert(t,4);
  //t = insert(t,2);
  //t = insert(t,1);
  //t = insert(t,6);
  //t = insert(t,8);
  inOrder(t);
  cout<<endl;
  int sum = 0;
  greate_sum_tree(t,sum);
  inOrder(t);
  //t = deletebst(t,4);
  //cout<<endl<<search(t,4);
  //inOrder(t);
  //preOrder(t);
  //cout<<endl;
  //postOrder(t);
  //cout<<endl;
  //levelOrder(t);
  //delTree(t);
  //inOrder(t);
  return 0;
}
