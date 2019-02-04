/*
  https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
  slow and fast pointer method.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *n;
}Node;
Node *makeNode(int d)
{
   Node *t =(Node *)malloc(sizeof(Node));
   t->d = d;
   t->n = NULL;
   return t;
}
Node *push(Node *h,int d)
{
   if(h==NULL)
   {
     h = makeNode(d);
     return h;
   }
   Node *t = makeNode(d);
   t->n = h;
   h = t;
   return h;
}
void print(Node *h)
{
  Node *t = h;
  while(t)
  {
    cout<<t->d<<"\t";
    t = t->n;
  }
  cout<<endl;
}
void middle(Node *h)
{
  Node *s = h;
  Node *f = h;
  while(f && f->n!=NULL)
  {
    s = s->n;
    f = f->n->n;
  }
  cout<<s->d<<endl;
}
Node *popList(void)
{
  Node *t = push(NULL,5);
  t = push(t,4);
  t = push(t,3);
  t = push(t,2);
  t = push(t,1);
  return t;
}
int main()
{
  Node *t = popList();
  print(t);
  middle(t);
  return 0;
}
