#include<iostream>
#include<set>
using namespace std;
int main()
{
  multiset<int> s={1,1,1,1};
  for(auto i: s)
   cout<<i<<"\t";
  s.clear();
  return 0;
}
