#include<iostream>
#include<set>
using namespace std;
int main()
{
  multiset<int> s;
  s.insert(10);
  s.insert(10);
  for(auto i: s)
  {
    cout<<i<<"\t";
  }
  s.clear();
  return 0;
}
