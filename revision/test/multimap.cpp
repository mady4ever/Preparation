#include<iostream>
#include<map>
using namespace std;
int main()
{
  multimap<int,int> mmp={{1,100},{1,200}};
  for(auto i: mmp)
  {
    cout<<i.first<<"\t"<<i.second<<endl;
  }
  mmp.clear();
  return 0;
}
