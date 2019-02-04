/*
Populate Inorder Successor for all nodes
Given a Binary Tree where each node has following structure, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

filter_none
edit
play_arrow

brightness_4
struct node 
{ 
  int data; 
  struct node* left; 
  struct node* right; 
  struct node* next; 
} 
Initially, all next pointers have NULL values. Your function should fill these next pointers so that they point to inorder successor.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *l,*r;
    Node *n;
}Node;
Node * makeNode(int d)
{
   Node *t = (Node *)malloc(sizeof(Node));
   if(t)
   {
     t->d = d;
     t->l = t->r = t->n =  NULL;
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
void fixInorderSuccessor(Node *r, Node *suc)
{
  if(r==NULL)
  {
    //suc = r;
    return;
  }
  fixInorderSuccessor(r->r, suc);
  r->n = suc;
  suc = r;
  fixInorderSuccessor(r->l, suc);
}
void printInOrderSuc(Node *t)
{
   if(t==NULL)
     return;
   printInOrderSuc(t->l);
   cout<<t->d<<"\t";
   if(t->n)
     cout<<t->n->d<<endl;
   else
     cout<<"NULL"<<endl;
   printInOrderSuc(t->r);
}
int main()
{
  Node *t = popTree();
  inOrder(t);
  cout<<endl;
  Node *suc=NULL;
  fixInorderSuccessor(t,suc);
  printInOrderSuc(t);
 // cout<<endl;
 // preOrder(t);
 // cout<<endl;
 // postOrder(t);
 // cout<<endl;
 // levelOrder(t);
 // delTree(t);
 // inOrder(t);
  return 0;
}
