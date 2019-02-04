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
bool mirror(Node *r)
{
   if(r==NULL)
     return true;
   if(r->l==NULL && r->r == NULL)
     return true;
   if(r->l && r->r && r->l->d == r->r->d )
     return true;
   return false;
}
bool isMirror(Node *r1, Node *r2)
{
   if(r1 == NULL && r2 == NULL)
     return true;
   if(r1 == NULL || r2 == NULL)
     return false;
   return (r1->d == r2->d) && 
          isMirror(r->l,r->r) && 
          isMirror(r->r, r->l);
}
int main()
{
  Node *t = popTree();
  inOrder(t);
  cout<<endl;
  preOrder(t);
  cout<<endl;
  postOrder(t);
  cout<<endl;
  levelOrder(t);
  cout<<mirror(t);
  //delTree(t);
  //inOrder(t);
  return 0;
}
