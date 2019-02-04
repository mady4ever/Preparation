#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
  unordered_multiset<int> ums = {1,1,2,3};
  for(auto i: ums)
    cout<<i<<"\t";
  ums.clear();
  return 0;
}
