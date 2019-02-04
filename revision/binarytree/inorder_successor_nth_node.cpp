/*
  find-n-th-node-inorder-traversal
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
void inOrderSuc(Node *r, Node *pre, int d)
{
   if(r==NULL) return;
   inOrderSuc(r->r,pre,d);
   if(r->d == d)
   {
     if(pre)
       cout<<pre->d<<endl;
     else
       cout<<"NULL"<<endl;
   }
   pre = r;
  inOrderSuc(r->l,pre,d);
}
void nthInorder(Node *r,int &n)
{
   if(r==NULL || n < 0)
    return;
   nthInorder(r->l,n);
   if(n==0)
     cout<<r->d<<endl;
   n--;
   nthInorder(r->r,n);   
}
int main()
{
  Node *t = popTree();
  inOrder(t);
  cout<<endl;
  //Node *pre = NULL;
  //inOrderSuc(t,pre,0);
  int nth = 1;
  nthInorder(t,nth);
 // preOrder(t);
 // cout<<endl;
 // postOrder(t);
 // cout<<endl;
 // levelOrder(t);
 // delTree(t);
 // inOrder(t);
  return 0;
}
