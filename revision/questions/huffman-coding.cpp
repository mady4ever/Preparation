/*
  https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
  use max heap to get the elements with there frquency.
  create max heap with frequency and elements.
  while heap is not empty insert root/top node to the binary tree.
  now travers the tree and create huffman code.
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
   char d;
   int f;
   Node *l;
   Node *r;
}Node;
Node *makeNode(char d,int f)
{
   Node *t = (Node *)malloc(sizeof(Node));
   t->l = t->r = NULL;
   t->d = d;
   t->f = f;
   return t;
}
void LogData(Node *t)
{
   cout<<endl;
   cout<<t->d<<"\t"<<t->f<<"\t";
}
Node *buildHuffman(char a[],int f[],int s)
{
  auto comp=[](Node *a,Node *b){return a->f < b->f;};
  priority_queue<Node*,vector<Node*>,decltype(comp)> pq(comp); // min heap.
  for(int i=0;i<s;i++)
  {
    Node *t = makeNode(a[i],f[i]);
    //LogData(t);
    pq.push(t);    
  }
  //while(!pq.empty())
  //{
  //  Node *t = pq.top();
  //  pq.pop();
  //  LogData(t);
  //}
  while(pq.size()>1)
  {
   // int d=0;
   // Node *l = pq.top();
   // pq.pop();
   // Node *r=NULL;
   // d+=l->f;
   // if(pq.size()>=1)
   // {
   //   r = pq.top();
   //   pq.pop();
   //   d+=r->f;
   // }
   // Node *m = makeNode('$',d);
   // m->l=l;
   // m->r=r;
   // pq.push(m);
    //LogData(m);
   Node *l = pq.top();
   pq.pop();
   Node *r = pq.top();
   pq.pop();
   Node *m = makeNode('$',l->f + r->f);
   m->l = l;
   m->r = r;
   pq.push(m);
  }
  Node *result = pq.top();
  pq.pop();
  return pq.size()==0 ? result:NULL;
}
void InOrder(Node *r)
{
  if(r)
  {
    InOrder(r->l); 
    LogData(r);
    InOrder(r->r);
  }
}
void LevelOrderTraversal(Node *r)
{
   if(r==NULL) return;
   list<Node *> q;
   q.push_back(r);
   int size=q.size();
   while(!q.empty())
   {
     size = q.size();
     while(size)
     {
       Node *t = q.front();
       q.pop_front();
       cout<<t->d<<"\t";
       if(t->l)
         q.push_back(t->l);
       if(t->r)
         q.push_back(t->r); 
       size--;
     }
     cout<<endl;
   }
}
void huffmanCodes(Node *r, string output)
{
  if(r==NULL)
  {
    //cout<<output<<endl;
    return;
  }
  huffmanCodes(r->l,"0"+output);
  huffmanCodes(r->r,"1"+output);
  if(r->l == NULL && r->r == NULL)
  {
    //LogData(r);
    cout<<output<<endl;
    return;
  }
}
void codes(Node *r,int arr[],int index)
{
  if(r->l)
  { 
    arr[index] = 0;
    codes(r->l,arr,index+1);
  }
  if(r->r)
  {
    arr[index] = 1;
    codes(r->r,arr,index+1);
  }
  if(r->l==NULL && r->r==NULL)
  {
    for(int i=0;i<5;i++)
    {
      cout<<arr[i];
    }
    cout<<endl;
  }
}
int main()
{
  char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
  int freq[] = { 5, 9, 12, 13, 16, 45 };   
  int size = sizeof(arr) / sizeof(arr[0]); 
  Node *m = buildHuffman(arr,freq,size);
  //InOrder(m);
  //LevelOrderTraversal(m);
  //huffmanCodes(m,"");
  int arrr[]={0,0,0,0,0};
  codes(m,arrr,0);
  return 0;
}
