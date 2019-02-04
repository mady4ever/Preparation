#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *l,*r;
}Node;
Node *makeNode(int d)
{
  Node *t=(Node *)malloc(sizeof(Node));
  t->d = d;
  t->l = t->r = NULL;
  return t;
}
Node *insert(Node *r,int d)
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
   t = insert(t,2);
   t = insert(t,8);
   t = insert(t,1);
   t = insert(t,3);
   t = insert(t,6);
   t = insert(t,9);
   return t;
}
void printVector(vector<int> path)
{
   for(auto i: path)
     cout<<i<<"\t";
   cout<<endl;
}
void printRootToLeafPath(Node *r,vector<int> path)
{
  if(r==NULL)
    return;
  path.push_back(r->d);
  if(r->l==NULL && r->r == NULL)
  {  
    printVector(path);
  }
  printRootToLeafPath(r->l,path);
  printRootToLeafPath(r->r,path);
  path.pop_back();
}
int main()
{
   Node *t = popTree();
   vector<int> path;
   printRootToLeafPath(t,path);
   return 0;
}
