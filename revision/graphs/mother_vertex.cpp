/*
Find a Mother Vertex in a Graph
A vertex from all the other vertices are visited/reachable.
ANS: 1] Idea is to do the  DFS and find the last visited virtice.
     2] Check the last visited virtice is the mother vitice or not by doing DFS again.
     3] In above check all the vitices are visited or not.

*/
#include<bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<int> g[], int a, int b)
{
   g[a].push_back(b);
   //g[b].push_back(a); // make it directed graph.
}
void popGraph(vector<int> g[])
{
   addEdge(g,0,1);
   addEdge(g,1,2);
   addEdge(g,2,3);
   addEdge(g,3,4);
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
void isMother(vector<int> g[])
{
   cout<<"+++++++++++++Mother+++++++++++++++"<<endl;
   vector<bool> isVisited;
   for(int i=0;i<V;i++)
       isVisited.push_back(false);
   int mother = 0;
   for(int i=0;i<V;i++)
   {
       if(isVisited[i] == false)
       {
         DFSUtil(g,i,isVisited);
         mother = i;  // note the last visited node. 
       }
   }
   for(int i=0;i<V;i++)
     isVisited[i] = false;
   //visit again.
   DFSUtil(g,mother,isVisited);
   for(int i=0;i<V;i++)
      if(isVisited[i]==false)
      {
         cout<<"Not Mother Vitex";
         return;
      } 
   cout<<"Mother vertex is :"<<mother<<endl;
}
int main()
{
  vector<int> g[V];
  popGraph(g); 
  print(g);
  BFS(g);
  cout<<endl;
  DFS(g);
  isMother(g);
  return 0;
}
