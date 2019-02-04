/*
  https://youtu.be/6ZRhq2oFCuo
*/
#include<bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<int> g[], int s, int d)
{
  g[s].push_back(d);
  g[d].push_back(s);
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
bool isCycleUtil(vector<int> g[],int index, vector<bool> isVisited, int parent)
{
  isVisited[index] = true;
  for(auto i: g[index])
  {
     if(!isVisited[i])
     {
        if(isCycleUtil(g,i,isVisited,index))
            return true;        
     }
     else if(parent != i)
       return true;
  }
  return false;
}
void isCycle(vector<int> g[])
{
  vector<bool> isVisited(V,false);
  int parent = -1;
  for(int i=0;i<V;i++)
  {
     if(!isVisited[i])
     {
       if(isCycleUtil(g,i,isVisited, parent))
       {
          cout<<"Cycle Present"<<endl;       
          return;
       }
     }
  }
  cout<<"\nNo Cycle\n";
}
int main()
{
  vector<int> g[V];
  addEdge(g,0,1);
  addEdge(g,1,2);
  addEdge(g,2,3);
  addEdge(g,3,4);
  addEdge(g,4,0); 
  printG(g);
 // topological(g,0);
  isCycle(g);
  return 0;
}
