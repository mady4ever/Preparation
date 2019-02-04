#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *l,*r;
}Node;
Node * makeNode(int d)
{
   Node *t = (Node *)malloc(sizeof(Node));
   t->d = d;
   t->l = t->r = NULL;
   return t;
}
Node *popTree(void)
{
   //    0
   //  1   2
   Node *t = makeNode(0);
   t->l = makeNode(1);
   t->r = makeNode(2);
   return t;
}
void inOrder(Node *r)
{
   if(r)
   {
     inOrder(r->l);
     cout<<r->d<<"\t";
     inOrder(r->r);
   }
}
void stack_inOrder(Node *r)
{
   if(r==NULL) return;
   stack<Node *> st;
   Node *c = r;
   while(c!=NULL || !st.empty())
   {
     while(c!=NULL)
     {
       st.push(c);
       c = c->l;
     }
     c = st.top();
     st.pop();
     cout<<c->d<<"\t";
     c = c->r;
   }
}
int main()
{
   Node *t = popTree();
   //inOrder(t);
   stack_inOrder(t);
   return 0;
}
