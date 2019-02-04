#include<bits/stdc++.h>
using namespace std;
class graph{
  private:
    vector<int> *lst;
    int V;
    bool isdirected;
  public:
   graph(int vv,bool isd):V(vv),isdirected(isd){
     lst = new vector<int>[V];
   };
   void addEdge(int s,int d);
   bool isCycle(void);
   bool isCycleUtil(int index,vector<bool> &isvisited, vector<bool> &rec);
   void pop(void);
   void print(void);
};
void graph::addEdge(int s, int d)
{
   lst[s].push_back(d);
   if(!isdirected)
   lst[d].push_back(s);
}
bool graph::isCycleUtil(int index, vector<bool> &isvisited, vector<bool> &rec)
{
   isvisited[index]= true;
   rec[index] = true;
   for(auto i: lst[index])
   {
     if(!isvisited[i])
     {
       if(isCycleUtil(i,isvisited,rec))
           return true;
     }
     else if(rec[i])
           return true;
   }
  rec[index] = false;
  return false;
}
bool graph::isCycle(void)
{
   vector<bool> isvisited(V,false); // isvisited to avaid cycle.
   vector<bool> rec(V,false); //recursion stack.
   for(int i=0;i<V;i++)
   {
        if(isvisited[i]==false)
        {
          if(isCycleUtil(i,isvisited,rec))
          {
              cout<<"Cycle Detected";
              return true;
          }
        }
   }
   cout<<"No Cycle";
   return false;
}
//populate graph.
void graph::pop(void)
{
  addEdge(0,1);
  addEdge(1,2);
  addEdge(2,3);
  addEdge(3,0); 
}
//print the graph.
void graph::print(void)
{
  for(int i=0;i<V;i++)
  {
    cout<<i<<" :";
    for(auto j: lst[i])
      cout<<j<<"\t";
    cout<<endl;
  }
}
int main()
{
  graph *g = new graph(4,true);
  g->pop();
  g->print();
  g->isCycle();   
}
