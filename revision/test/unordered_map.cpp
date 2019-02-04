#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
  unordered_map<int,int> umap={{1,100},{2,200}};
  for(auto i:umap)
    cout<<i.first<<"\t"<<i.second<<"\n";
  umap.clear();
  return 0;
}
