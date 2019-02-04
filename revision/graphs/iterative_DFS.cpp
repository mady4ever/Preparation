#include<bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<int> g[], int a, int b)
{
   g[a].push_back(b);
   g[b].push_back(a);
}
void popGraph(vector<int> g[])
{
   addEdge(g,0,1);
   addEdge(g,1,2);
   addEdge(g,1,4);
   addEdge(g,2,4);
}
void print(vector<int> g[])
{
   for(int i=0;i<V;i++)
   {
     cout<<i<<" :";
     for(auto j : g[i])
     {
        cout<<j<<"\t";
     }
     cout<<endl;
   }
}
void BFS(vector<int> g[])
{
  cout<<"++++++++++++++++BFS+++++++++++++"<<endl;
  vector<bool> isVisited;
  for(int i=0;i<V;i++)
     isVisited.push_back(false);
  list<int> current;
  current.push_back(0); // Initial from where bfs starts.
  isVisited[0] = true;
  while(!current.empty())
  {
    int node = current.front();
    current.pop_front();
    //isVisited[node] = true;
    cout<<node<<"\t";
    for(auto i : g[node])
    {
       if(isVisited[i] == false)
       {
         isVisited[i] = true;
         current.push_back(i);
       }
    }
  }
  cout<<endl;
}
void DFSUtil(vector<int> g[], int index, vector<bool> &isVisited)
{
   cout<<index<<"\t";
   isVisited[index] = true;
   for(auto j : g[index])
   {
       if(isVisited[j] == false)
         DFSUtil(g,j,isVisited);
   }
}
void DFS(vector<int> g[])
{
   cout<<"+++++++++++++++++++DFS++++++++++++++"<<endl;
   vector<bool> isVisited;
   for(int i=0;i<V;i++)
       isVisited.push_back(false);
   for(int i=0;i<V;i++)
   {  
      if(isVisited[i] == false)
        DFSUtil(g,i,isVisited);
      cout<<endl;
   }
}
void iterativeDFS(vector<int> g[])
{
  cout<<"+++++++++++++++++++Iterative DFS+++++++++++++++++"<<endl;
  vector<bool> isVisited;
  for(int i=0;i<V;i++)
  {
     isVisited.push_back(false);
  }
  stack<int> st;
  st.push(0); //take the 0 as start index.
  while(!st.empty())
  {
    int node = st.top();
    st.pop();
    if(isVisited[node] == false) 
    { 
      cout<<node<<"\t";
      isVisited[node] = true;
    }
    //visit all adjucents.
    for(auto j : g[node])
    {
       if(isVisited[j] == false)
       {
          st.push(j);
       }
    }
  }
  cout<<endl;
}
int main()
{
  vector<int> g[V];
  popGraph(g); 
  print(g);
  BFS(g);
  cout<<endl;
  DFS(g);
  iterativeDFS(g);
  return 0;
}
