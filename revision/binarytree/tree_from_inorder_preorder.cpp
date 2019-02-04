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
//Node *tree_from_in_pre(void)
//{
//  int in[] = {4, 2, 5, 1, 3, 6};
//  int pre[] = {1, 2, 4, 5, 3, 6};
//  int s =sizeof(in)/sizeof(in[0]);
//  int index =0;
//  Node *t = rec_in_pre(in,pre,0,s,index,s);
//  postOrder(t);
//  delTree(t);
//}
int index_of(int in[],int d,int size)
{
   for(int i=0;i<size;i++)
   {
     if(in[i]==d)
      return i;
   }
   return -1;
}
Node *rec_in_pre(int in[],int pre[],int l, int r, int &index, int s)
{
  cout<<l<<"\t"<<r<<"\t"<<index<<endl;
  if(l>r || index >= s)
   return NULL;
  Node *t = makeNode(pre[index++]);
  cout<<"Node :"<<t->d<<endl;
  int i = index_of(in,t->d,s);
  t->l = rec_in_pre(in, pre,l,i-1,index, s);
  t->r = rec_in_pre(in, pre,i+1, r,index,s);
  return t;
}
Node *tree_from_in_pre(void)
{
  //int in[] = {4, 2, 5, 1, 3, 6};
  //int pre[] = {1, 2, 4, 5, 3, 6};
  int in[] = {30,35,40,80,100};
  int pre[] = {40,30,35,80,100};
  int s =sizeof(in)/sizeof(in[0]);
  int index =0;
  Node *t = rec_in_pre(in,pre,0,s,index,s);
  postOrder(t);
  cout<<endl;
  inOrder(t);
  cout<<endl;
  preOrder(t);

  delTree(t);
}
int main()
{
  tree_from_in_pre();
  //Node *t = popTree();
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
