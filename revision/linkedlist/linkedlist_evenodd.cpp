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
  Node *t = push(NULL,1);
  t = push(t,2);
  t = push(t,3);
  t = push(t,4);
  return t;
}
Node * oddEven(Node *t)
{
   if(t == NULL)
     return NULL;
   Node *es = NULL;
   Node *ee = NULL;
   Node *os = NULL;
   Node *oe = NULL;
   //es = ee = os = oe = t;
   Node *c = t;
   while(c != NULL)
   {
     if( c->d % 2 == 0)
     {
        cout<<endl<<c->d<<endl;
        if(es == NULL)
        {
           es = c;
           ee = c;
        }
        else
        {
          ee->n = c;
          ee = ee->n;
        }
     }
     else
     {
        if(os == NULL)
        {
           os = oe = c;           
        }
        else
        {
          oe->n = c;
          oe = oe->n;
        }
     }
     c = c->n;
   }
   if(ee)
     ee->n = NULL;
   if(oe)
     oe->n = NULL;
   ee->n = os;
   return es;
}
int main()
{
  cout<<"C++ Linked List";
  Node *t = popList();
  print(t);
  t = oddEven(t);
  print(t);
  t = deletel(t);
  return 0;
}
