/*
https://www.geeksforgeeks.org/level-order-tree-traversal/
 Use BFS to travers the tree level order.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *l,*r;
}Node;
Node *makeNode(int d)
{
  Node *t = (Node *)malloc(sizeof(Node));
  t->d = d;
  t->l = t->r = NULL;
  return t;
}
Node * insert(Node *r, int d)
{
  if(r==NULL)
    return makeNode(d);
  if(d < r->d)
   r->l = insert(r->l,d);
  else
   r->r = insert(r->r,d);
  return r;
}
Node *popTree(void)
{
   Node *t = insert(NULL,5);
   t = insert(t,8);
   t = insert(t,3);
   t = insert(t,2);
   t = insert(t,9);
   return t;
}
void levelOrder(Node *r)
{
   if(r==NULL)
     return;
   list<Node *> lst;
   lst.push_back(r);
   int c=0; //lst.size();
   while(!lst.empty())
   {
     c = lst.size();
     for(int i=0;i<c;i++)
     {
       Node *t = lst.front();
       lst.pop_front();
       if(t)
         cout<<t->d<<"\t";
       if(t && t->l)
         lst.push_back(t->l);
       if(t && t->r)
         lst.push_back(t->r);
     }
     cout<<endl;
   }
}
int main()
{
  Node *t = popTree();
  levelOrder(t);
  return 0;
}
