/*
  https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
  if leaf node then immidiatly returned it otherwise create the left and right child.
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
Node *createTree(int a[],int s,int &i,char p[])
{
   if(i>s) return NULL;

   Node *t = makeNode(a[i++]);

   if(p[i-1]=='L')
    return t;
   t->l = createTree(a,s,i,p);
   t->r = createTree(a,s,i,p);
   return t;
}
void PreOrder(Node *t)
{
  if(t)
  {
    cout<<t->d<<"\t";
    PreOrder(t->l);
    PreOrder(t->r);
  }
}
int main()
{
  int pre[] = {10, 30, 20, 5, 15}; 
  char preLN[] = {'N', 'N', 'L', 'L', 'L'}; 
  int n = sizeof(pre)/sizeof(pre[0]);
  int index = 0;
  Node *t = createTree(pre,n,index,preLN);
  PreOrder(t);
  return 0;
}
