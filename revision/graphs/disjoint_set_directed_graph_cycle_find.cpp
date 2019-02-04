/*
  https://www.geeksforgeeks.org/union-find/
*/
#include<bits/stdc++.h>
using namespace std;
#define V 4
void addEdge(vector<int> g[],int s,int d)
{
   g[s].push_back(d);
   //g[d].push_back(s);
}
int find(int p[],int x)
{
   if(p[x]==-1)
     return x;
   return find(p,p[x]);
}
void dunino(int p[], int x, int y)
{
   int xx = find(p, x);
   int yy = find(p, y);
   p[xx] = yy;
}
void isCycle(vector<int> g[])
{
  int p[]={-1,-1,-1,-1,-1};
  for(int i=0;i<V;i++)
  {
    for(auto j: g[i])
    {
      int x = find(p,i);
      int y = find(p,j);
      if(x==y)
      {
        cout<<"Cycle Present";
        return;
      }
      dunino(p,x,y);
    } 
  }
  cout<<"No Cycle"; 
}
void print(vector<int> g[])
{
  for(int i=0;i<V;i++)
  {
    cout<<i<<" :";
    for(auto j: g[i])
      cout<<j<<"\t";
    cout<<endl;
  }
}
int main()
{
   vector<int> g[V];
   addEdge(g,0,1);
   addEdge(g,1,2);
   addEdge(g,2,3);
   addEdge(g,3,0);
   print(g);
   isCycle(g); 
}
