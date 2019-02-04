#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d;
    Node *l,*r;
}Node;
Node * makeNode(int d)
{
   Node *t = (Node *)malloc(sizeof(Node));
   if(t)
   {
     t->d = d;
     t->l = t->r = NULL;
     return t;
   }
   return NULL;
}
Node* popTree(void)
{
   Node *t = makeNode(0);
   t->l = makeNode(1);
   t->r = makeNode(2);
   return t;
}
void inOrder(Node *r)
{
   if(r==NULL)
     return;
   inOrder(r->l);
   cout<<r->d<<"\t";
   inOrder(r->r);
}
void preOrder(Node *r)
{
   if(r==NULL)
     return;
   cout<<r->d<<"\t";
   preOrder(r->l);
   preOrder(r->r);
}
void postOrder(Node *r)
{
   if(r==NULL)
     return;
   postOrder(r->l);
   postOrder(r->r);
   cout<<r->d<<"\t";
}
void delTree(Node *r)
{
   if(r==NULL)
    return;
   if(r->l == NULL && r->r == NULL)
   {
      free(r);
      r = NULL;
      return;
   }
   delTree(r->l);
   delTree(r->r);
}
void levelOrder(Node *r)
{
   if(r==NULL)
     return;
   queue<Node *> q;
   q.push(r);
   while(!q.empty())
   {
     Node *t = q.front();
     q.pop();
     if(t==NULL)
       continue;
     cout<<t->d<<"\t";
     if(t->l !=NULL)
       q.push(t->l);
     if(t->r != NULL);
       q.push(t->r);
   }
}
vector<Node *> all_trees(int arr[], int s, int e)
{
   vector<Node *> t;
   if(s>e)
   {
      t.push_back(NULL);
      return t;
   }
   for(int i=s;i<=e;i++)
   {
      vector<Node *> lt = all_trees(arr,s,i-1);
      vector<Node *> rt = all_trees(arr,i+1,e);
      for(int j=0;j< lt.size(); j++)
      {
         for(int k=0; k< rt.size(); k++)
	 {
           Node *r = makeNode(arr[i]);
	   r->l = lt[j];
	   r->r = rt[k];
	   t.push_back(r);
	 }
      }
   }
   return t;
}
int main()
{
 int arr[]={4, 5, 7};
 int s = sizeof(arr)/sizeof(arr[0]);
 vector<Node *> vr = all_trees(arr,0,s-1);
 for(int i=0;i< vr.size();i++)
 {
   preOrder(vr[i]);
   cout<<endl;
 }
 // Node *t = popTree();
 // inOrder(t);
 // cout<<endl;
 // preOrder(t);
 // cout<<endl;
 // postOrder(t);
 // cout<<endl;
 // levelOrder(t);
 // delTree(t);
 // inOrder(t);
  return 0;
}
