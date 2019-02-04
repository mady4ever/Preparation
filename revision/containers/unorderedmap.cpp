#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
  unordered_map<int,string> ump= {{1,"abc"},
                               {1,"abz"},
			       {1,"abzz"}};
  for(auto i: ump)
  {
    cout<<i.first<<"\t"<<i.second<<"\n";    
  }
  ump.clear();
  return 0;
}
