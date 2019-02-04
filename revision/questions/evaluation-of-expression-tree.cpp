/*
   https://www.geeksforgeeks.org/evaluation-of-expression-tree/
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
   int ch;
   Node *l,*r;
}Node;
Node *makeNode(int d)
{
  Node *t=(Node *)malloc(sizeof(Node));
  t->ch = d;
  t->l = t->r = NULL;
  return t;
}
Node *popTree(void)
{
  Node *r = makeNode(int('*'));
  r->l = makeNode(int('+'));
  r->r = makeNode(10);
  r->l->l = makeNode(10);
  r->l->r = makeNode(20);
  //        *
  //     +    10
  //  10   20
  //
  return r;  
}
int solveExpression(Node *r)
{
   if(r==NULL)
    return 0;
   if(r->l == NULL && r->r == NULL)
      return r->ch;
   if(!isdigit(r->ch))
   {
     if(char(r->ch) == '*')
       return solveExpression(r->l) * solveExpression(r->r);
     else if(char(r->ch) == '/')
       return solveExpression(r->l)/solveExpression(r->r);
     else if(char(r->ch) == '+')
       return solveExpression(r->l) + solveExpression(r->r);
     else if(char(r->ch) == '-')
       return solveExpression(r->l) - solveExpression(r->r);
     else //raise exception for unsupported operation.
       return -1;
   }
}
int main()
{
  Node *t = popTree();
  cout<<solveExpression(t);
  return 0;
}
