/*
  topological sorting.
  https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
*/
#include<bits/stdc++.h>
using namespace std;
class graph{
   int V;
   vector<int> *lst;
   bool *isvisited;
   public:
   graph(int v):V(v){
     lst = new vector<int>[V];
     isvisited = new bool[V];
   };
   void addEdge(int a,int b);
   void topologicalSort(int start);
   void topologicalSortUtil(int a,stack<int> &st);
   void populate(vector<string> input);
   void printG(void);
};
void graph::addEdge(int a, int b)
{
   lst[a].push_back(b);
}
void graph::topologicalSortUtil(int i, stack<int> &st)
{
   isvisited[i] = true;
   for(auto j : lst[i]) // visit neighbours of i.
   {
     if(isvisited[j]==false)
        topologicalSortUtil(j,st);
   }
   st.push(i);
}
void graph::topologicalSort(int start)
{
  stack<int> st;
  //for(int i=0;i<V;i++)
  //  isvisited[i] = false;
  for(int i=0;i<V;i++)
  {
    if(isvisited[i]==false)
      topologicalSortUtil(i,st);
  }
 // for(auto i: lst[start])
 // {
 //   if(isvisited[i] == false)
 //      topologicalSortUtil(i,st);      
 // }
  while(!st.empty())
  {
    cout<<char(st.top()+'a')<<"\t";  
    st.pop();
  }
}
void graph::populate(vector<string> input)
{
  for(int i=1;i<input.size();i++)
  {
    int j=0;
    int k=0;
    while(j<input[i-1].size() && k < input[i].size())
    {
       if(input[i-1][j] == input[i][k])
       {
          j++;
          k++;
       }
       else
       {
         addEdge(input[i-1][j]-'a',input[i][k]-'a');
         break;
       }
    }
  }
}
void graph::printG(void)
{
  for(int i=0;i<V;i++)
  {    
    cout<<i<<" :";
    for(int j=0;j<lst[i].size();j++)
      cout<<lst[i][j]<<"\t";

    cout<<endl;
  }
}
int main()
{
  vector<string> input = {"baa", "abcd", "abca", "cab", "cad"};
  //vector<string> input = {"caa", "aaa", "aab"}; 
  graph *g = new graph(input.size()-1);
  g->populate(input);
  //g->printG();
  for(int i=0;i<input.size()-1;i++)
    g->topologicalSort(i);
  return 0;
}
