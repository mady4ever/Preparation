#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
  multimap<int, string> mp={{1,"A"},
                       {2,"B"},
		       {3,"C"},
		       {4,"D"},
                       {1,"AA"}};
  for(auto i:mp)
  {
    cout<<i.first<<"\t"<<i.second<<"\n";    
  }
  mp.clear();
  cout<<"map size:"<<mp.size()<<"\n";
  return 0;
}
