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
   Node *t = makeNode(2);
   t->l = makeNode(1);
   t->r = makeNode(3);
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
bool isContineous(Node *r)
{
   if(r==NULL)
    return true;
   if(r->l == NULL && r->r == NULL)
    return true;
   if(r->r!=NULL)
     return (abs(r->d - r->r->d) == 1) && isContineous(r->r);
   if(r->l!=NULL)
     return (abs(r->d - r->l->d) == 1) && isContineous(r->l);
   return (abs(r->d - r->r->d) == 1) &&
          (abs(r->d - r->l->d) == 1) &&
          isContineous(r->r) &&
          isContineous(r->l);
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
  cout<<isContineous(t);
  //delTree(t);
  //inOrder(t);
  return 0;
}
