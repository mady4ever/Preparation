#include<bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<int> g[], int s, int d)
{
  g[s].push_back(d);
}
void printG(vector<int> g[])
{
  for(int i=0;i<V; i++)
  {
     cout<<i<<" :";
     for(auto j : g[i])
       cout<<j;
     cout<<endl;
  }
}
void topoUtil(vector<int> g[],int start, vector<bool> &isVisited, stack<int> &st)
{
   isVisited[start] = true;
   for(auto i: g[start])
   {
      if(!isVisited[i])
      {
           topoUtil(g,i,isVisited,st);
      }
   }
   st.push(start);
}
void topological(vector<int> g[], int start)
{
   cout<<endl<<"++++++++++++++++++TOPO+++++++++++\n";
   vector<bool> isVisited(V,false);
   stack<int> st;
   if(isVisited[start] == false)
      topoUtil(g,start,isVisited,st);
   while(!st.empty())
   {
     cout<<st.top();
     st.pop(); 
   }
}
int main()
{
  vector<int> g[V];
  addEdge(g,0,1);
  addEdge(g,1,2);
  addEdge(g,2,3);
  addEdge(g,3,4); 
  printG(g);
  topological(g,0);
  return 0;
}
