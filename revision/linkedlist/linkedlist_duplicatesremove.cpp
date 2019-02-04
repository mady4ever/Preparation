/*
  Linked list: Operations 1] Creation of linked list.
                          2] Deletion of linked list.
                          3] Printing of linked list.
			  4] Push the elements at the start of the linked list.

*/
#include<iostream>
#include<exception>
#include<map>
using namespace std;
typedef struct Node
{
    int d;
    Node *n;
}Node;
Node* makeNode(int d)
{
  try
  {
  	Node *t =(Node *)malloc(sizeof(Node));
  	if(t)
  	{ 
    	  t->d = d;
    	  t->n = NULL;
    	  return t;
  	}
  }
  catch(exception e)
  {
     cout<<"Exception Occurred!";
  }
  return NULL;
}
Node* push(Node *h,int d)
{
   if(h==NULL)
     return makeNode(d);
   else
   {
     Node *t = makeNode(d);
     t->n = h;
     return t;
   }
   return NULL;
}
void print(Node *t)
{
  cout<<"\nPrinting the list\n";
  while(t != NULL)
  {
     cout<<t->d<<"\t";
     t = t->n;
  }
}
Node* deletel(Node *t)
{
   Node *tt = NULL;
   while(t->n!=NULL)
   {
     tt = t;
     t = t-> n;
     free(tt);
     tt = NULL;
   }
   return NULL;
}
Node * popList(void)
{
  Node *t = push(NULL,10);
  t = push(t,20);
  t = push(t,30);
  t = push(t,40);
  t = push(t,20);
  t = push(t,10);
  return t;
}
Node * removeduplicates(Node *h)
{
   if(h==NULL)
    return h;
   map<int,int> hm;
   Node *c = h;
   Node *p = NULL;
   hm.insert(make_pair(c->d,1));
   while(c && c->n != NULL)
   {
       if(hm.count(c->n->d) == 0)
       {
          // new element no duplicates.
          hm.insert(make_pair(c->n->d,1));
          //c = c->n;
       }
       else
       {
          // duplicate found.
          Node *t = c->n->n;
          free(c->n);
          p = c;
          c = t;
          continue;
       }
       p = c;
       c = c->n;
   }
   if(c && c->n == NULL)
   {
     if(hm.count(c->d) > 0)
     {
        p->n = NULL;
        free(c);
     }
   }     
   return h;
}
int main()
{
  cout<<"C++ Linked List";
  Node *t = popList();
  print(t);
  t = removeduplicates(t);
  print(t);
  t = deletel(t);
  print(t);
  return 0;
}
