/*
  Linked list: Operations 1] Creation of linked list.
                          2] Deletion of linked list.
                          3] Printing of linked list.
			  4] Push the elements at the start of the linked list.

*/
#include<iostream>
#include<exception>
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
  return t;
}
int main()
{
  cout<<"C++ Linked List";
  Node *t = popList();
  print(t);
  t = deletel(t);
  print(t);
  return 0;
}
