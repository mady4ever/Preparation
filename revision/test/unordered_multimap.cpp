#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
  unordered_multimap<int,int> umap={{1,100},{1,200}};
  for(auto i:umap)
    cout<<i.first<<"\t"<<i.second<<"\n";
  umap.clear();
  return 0;
}

