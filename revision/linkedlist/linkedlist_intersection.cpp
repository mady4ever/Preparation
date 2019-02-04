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
Node * popListOther(void)
{
  Node *t = push(NULL,11);
  t = push(t,21);
  t = push(t,31);
  t = push(t,41);
  return t;
}
/*
Node * merge(Node *t, Node *tt)
{
   if(t==NULL)
    return tt;
   if(tt == NULL)
    return t;
   Node *c = NULL;
   while(t !=NULL || tt !=NULL)
   {
      if(t && tt)
      {
         if(t->d > tt->d)
            
      }
   } 
}
*/
Node * copyl(Node *t)
{
   if(t==NULL)
    return NULL;
   Node *tt = makeNode(t->d);
   tt->n = copyl(t->n);
   return tt;
}
Node * merger(Node *o, Node *t)
{   
   if(o==NULL && t==NULL)
     return NULL;
   if(o == NULL) return copyl(t);
   if(t== NULL) return copyl(o);
   cout<<o->d<<" "<<t->d<<endl;
   //Node *c = NULL;
   Node *temp = makeNode(0);
   if(o->d > t->d)
   {
       temp->d = o->d;
       temp->n = merger(o->n,t);
   }
   else if( o->d < t->d)
   {
      temp->d = t->d;
      temp->n = merger(o, t->n);
   }
   else
   {
   	//both have same value;
   	temp->d = o->d;
   	temp->n = merger(o->n,t->n);
   	//return temp;     
   }
   return temp;
}
int main()
{
  cout<<"C++ Linked List";
  Node *t = popList();
  print(t);
  Node *tt = popListOther();
  print(tt);
  Node *ttt = merger(t,tt);
  cout<<endl;
  print(ttt);
  t = deletel(t);
  print(t);
  return 0;
}
