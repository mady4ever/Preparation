#include<bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<int> g[], int a, int b)
{
   g[a].push_back(b);
   //g[b].push_back(a);
}
void popGraph(vector<int> g[])
{
   addEdge(g,0,1);
   addEdge(g,0,2);
   addEdge(g,1,4);
   addEdge(g,1,3);
   addEdge(g,3,2);
   addEdge(g,2,4);
   addEdge(g,0,4);
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
void numberOfPathsUtil(vector<int> g[],int index, int dest, int &paths)
{
   if(index == dest)
     paths++;
   //visit all the adjucents.
   for(auto i : g[index])
   {
      numberOfPathsUtil(g,i,dest,paths);  
   }
}
void numberOfPaths(vector<int> g[])
{
  //Assuming graph is directed and has no cycles.
  cout<<"++++++++++Paths++++++++"<<endl;
  int paths = 0;
  numberOfPathsUtil(g,0,4,paths);
  cout<<paths<<endl;
}
void numPathsUtil(vector<int> g[], int index, int dest, int &paths,vector<bool> &isVisited)
{
  isVisited[index] = true;
  if(index == dest)
   paths++;
  else
  {
  for(auto i : g[index])
  {
    if(isVisited[i] == false)
      numPathsUtil(g,i,dest,paths,isVisited);
  }
  }
  isVisited[index] = false;
}
//number of paths with backtracking and avild cycles.
void numPaths(vector<int> g[])
{
   cout<<"++++++++++++Paths+++++++"<<endl;
   vector<bool> isVisited;
   for(int i=0;i<V;i++)
         isVisited.push_back(false);
   int paths = 0;
   numPathsUtil(g,0,4,paths,isVisited);
   cout<<paths<<endl;
}
int main()
{
  vector<int> g[V];
  popGraph(g); 
  print(g);
  BFS(g);
  cout<<endl;
  DFS(g);
  numberOfPaths(g);
  numPaths(g);
  return 0;
}
