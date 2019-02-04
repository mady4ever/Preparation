#include<iostream>
#include<unordered_set>
//#include<set>
using namespace std;
int main()
{
  unordered_multiset<int> us={1,1,1,1};
  for(auto i:us)
   cout<<i<<"\t";
  us.clear();
  return 0;
}
