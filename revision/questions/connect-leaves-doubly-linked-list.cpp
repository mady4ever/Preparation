/*
  https://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
  solution: 1] visit the nodes in pre order way.
            2] if it's a leaf node then add to DLL.
            3] follow above for left and right child.
            5] it's similar to insert in binary search tree for left and right traversal.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
     int d;
     Node *l,*r;
}Node;
Node * makeNode(int d)
{
   Node *t =(Node *)malloc(sizeof(Node));
   t->d = d;  //raise exception for memory full error or any allocation error.
   t->l = t->r = NULL;
   return t;
}
Node *popTree(void)
{
   //        5
   //     3     2
   //   1         7
   Node *t = makeNode(5);
   t->l = makeNode(3);
   t->r = makeNode(2);
   t->l->l = makeNode(1);
   t->r->r = makeNode(7);
   return t;
}
Node* createDLLofLeaves(Node *r, Node **head)
{
  if(r==NULL) 
    return NULL;
  if(r->l==NULL && r->r == NULL)
  {
    //Add this node to the list.
    r->r = *head;
    if(*head!=NULL) 
       (*head)->l = r;
    *head = r;
    return NULL;
  }
  r->l = createDLLofLeaves(r->l,head);
  r->r = createDLLofLeaves(r->r,head);
  return r;
}
void InOrder(Node *r)
{
  if(r)
  {
     InOrder(r->l);
     cout<<r->d<<"\t";
     InOrder(r->r);
  }
}
void PrintList(Node *r)
{
  Node *t = r;
  while(t)
  {
    cout<<t->d<<"\t";
    t = t->r;
  }
}
int main()
{
   Node *t = popTree();
   Node *h = NULL;
   InOrder(t);
   t = createDLLofLeaves(t,&h);
   cout<<endl;
   PrintList(h);
   return 0; 
}
