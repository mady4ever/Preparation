/*
Replace each node in binary tree with the sum of its inorder predecessor and successor
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
void inOrderVector(Node *r, vector<int> &v)
{
  if(r==NULL)
    return;
  inOrderVector(r->l,v);
  v.push_back(r->d);
  inOrderVector(r->r,v);
}
void Sum(Node *r, vector<int> &v, int &index)
{
   if(r==NULL)
     return;
   Sum(r->l,v,index);
   r->d = v[index-1] + v[index +1];
   index++;
   Sum(r->r,v,index);
}
void SumTree(Node *r)
{
   if(r==NULL)
     return;
   vector<int> v;
   v.push_back(0);
   inOrderVector(r,v);
   v.push_back(0);
   int index = 1;
   Sum(r,v,index);
   for(auto i: v)
     cout<<i<<"\t";
   cout<<endl;
   inOrder(r);
   cout<<endl;
}
int main()
{
  Node *t = popTree();
  SumTree(t);
  // 0 1 0 2 0
  // 0 0 2 2 0
  //inOrder(t);
  //cout<<endl;
  //preOrder(t);
  //cout<<endl;
  //postOrder(t);
  //cout<<endl;
  //levelOrder(t);
  //delTree(t);
  //inOrder(t);
  return 0;
}
