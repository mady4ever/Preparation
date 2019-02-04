/*
  https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
  Use min heap to get the next minimum from the list.
  calculate the range between min and max
  if any one of the list is exhusted then return the min range calculated so far.
*/
#include<bits/stdc++.h>
using namespace std;
#define N 5
typedef struct Node{
    int d; //data
    int l; //list from which this element is.
    int i; //index of this element in above list.
}Node;
Node *makeNode(int d,int l,int i)
{
   Node *t = (Node *)malloc(sizeof(Node));
   t->d = d;
   t->l = l;
   t->i = i;
   return t;
}
void LogData(Node *t)
{
   cout<<endl;
   cout<<t->d<<"\t"<<t->l<<"\t"<<t->i<<endl;
}
void solveRange(int arr[][N],int k)
{
  auto comp = [](Node *a, Node *b){ return a->d > b->d;};
  priority_queue<Node*,vector<Node*>,decltype(comp)> pq(comp);
  int max_e = 0;
  for(int i=0;i<k;i++)
  {
    Node *t = makeNode(arr[i][0],i,0);
    pq.push(t);
    max_e = max(max_e,t->d);
  } 
  //while(!pq.empty())
  //{
  //   Node *t =pq.top();
  //   cout<<t->d<<"\t"<<t->l<<"\t"<<t->i<<endl;
  //   pq.pop();
  //}
  int diff =INT_MAX;
  while(true)
  {
    Node *t = pq.top();
    pq.pop();
    diff = min(max_e - t->d,diff);
    if(t->i+1 > N) // check the range is exceeded.
     break;
    else
    {
      Node *tt = makeNode(arr[t->l][t->i+1],t->l,t->i+1);
      max_e = max(max_e,tt->d);
      pq.push(tt);
      //LogData(tt);
    }
  }
  cout<<"\n Range : "<<diff<<endl; 
}
int main()
{
  int arr[][N] = { 
                    {4, 7, 9, 12, 15}, 
                    {0, 8, 10, 14, 20}, 
                    {6, 12, 16, 30, 50} 
                    }; 
  int k = sizeof(arr)/sizeof(arr[0]);
  solveRange(arr,k); 
  return 0;
}
