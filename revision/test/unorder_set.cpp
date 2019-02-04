#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
  unordered_set<int> us = {1,3,4};
  for(auto i: us)
   cout<<i<<"\t";
  us.clear();
  return 0;
}
