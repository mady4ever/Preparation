/*
   loop in a linked list.
*/
#include<iostream>
using namespace std;
typedef struct Node{
    int d;
    Node *n;
}Node;
Node * makeNode(int d)
{
    Node *t = (Node *)malloc(sizeof(Node));
    if(t)
    {
      t->d = d;
      t->n = NULL;
      return t;
    }
    return NULL;
}
Node * push(Node *h, int d)
{
   if(h==NULL)
     return makeNode(d);
   else
   {
     Node *t = makeNode(d);
     t->n = h;
     return t;
   }
   // rasie the exception.
   return NULL;
}
void printList(Node *t);
Node *popList(void)
{
   Node *t = push(NULL, 0);
   t = push(t,1);
   t = push(t,2);
   t = push(t,3);
   t = push(t,4);
   //printList(t);
   //cout<<"\n"<<t->n->n->n->n->d;
   //cout<<"\t"<<t->n->n->d<<endl;
   t->n->n->n->n->n = t->n->n;
 //4  3  2  1  0      4  3  2 
   return t;
}
void printList(Node *t)
{
   while(t)
   {
      cout<<t->d<<"\t";
      t = t->n;
   }
   cout<<endl;
}
int count_nodes(Node *t, int d)
{
    if(t==NULL)
      return 0;
    if(t->d == d)
      return 1 + count_nodes(t->n,d);
    return count_nodes(t->n,d);
}
bool is_loop(Node *t)
{
   if(t==NULL)
     return false;
   Node *s = t;
   Node *f = t;
   cout<<"\ndetecting loop\n";
   while(f && f->n!=NULL && s->n != f->n)
   {
      cout<<s->d<<"\n";
      s = s->n;
      cout<<f->d<<"\n";
      f = f->n->n;
      if(s->n == f->n)
        break; 
   }
   cout<<"\ncorrecting loop\n";
   if(s->n == f->n)
     return true;
   return false;
}
void detect_loop_remove(Node *t)
{
  if(t==NULL)
    return;
  Node *s = t;
  Node *f = t;
  cout<<"\ndetecting loop\n";
  while(s && s->n !=NULL)
  {
     cout<<"slow: "<<s->d<<"\t";
     s = s->n;
     cout<<s->d<<"\n";
     cout<<"fast: "<<f->d<<"\t";
     f = f->n->n;
      cout<<f->d<<"\n";
     if(s->n == f->n)
        break;
  }
  cout<<"\ncorrecting loop \n";
  if(s->n == f->n)
  {
    //loop detected now remove the loop.
    s = t;
    while(s->n != f->n)
    {
      s = s->n;
      f = f->n;
    }
    f->n = NULL;
  } 
}
int main()
{
  Node *t = popList();
  detect_loop_remove(t);
  printList(t);
  //cout<<count_nodes(t,2)<<endl;
  return 0;
}
