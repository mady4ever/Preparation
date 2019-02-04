/*
  Count the number of nodes with given value in linked list.
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
Node *popList(void)
{
   Node *t = push(NULL, 0);
   t = push(t,1);
   t = push(t,2);
   t = push(t,2);
   t = push(t,4);
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
int main()
{
  Node *t = popList();
  printList(t);
  cout<<count_nodes(t,2)<<endl;
  return 0;
}
