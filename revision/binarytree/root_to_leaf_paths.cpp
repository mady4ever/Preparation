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
void rootPath(Node *r, vector<Node *> path)
{
   if(r==NULL) return;
   path.push_back(r);
   if((r->l == NULL && r->r==NULL))
   {
      for(auto i: path)
      {
        if(i)
        cout<<i->d<<"\t";
      }
      cout<<endl;
   }
   //path.push_back(r);
   rootPath(r->l,path);
   rootPath(r->r,path);
   path.pop_back();
}
int main()
{
  Node *t = popTree();
  //inOrder(t);
  //cout<<endl;
  //preOrder(t);
  //cout<<endl;
  //postOrder(t);
  cout<<endl;
  levelOrder(t);
  cout<<endl;
  vector<Node *> r;
  rootPath(t,r);
  //delTree(t);
  //inOrder(t);
  return 0;
}
