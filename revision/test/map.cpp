#include<iostream>
#include<map>
using namespace std;
int main()
{
  map<int,int> mp={{1,100},{2,200}};
  mp.insert(make_pair(3,300));
  for(auto i:mp)
  {
    cout<<i.first<<"\t"<<i.second<<endl;
  }
  mp.clear();
  return 0;
}
