#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(vector<int> v)
{
   for(auto i: v)
     cout<<i<<"\t";
   cout<<endl;
}
void check(vector<int> v)
{
   auto comp = [](int a){ return a%2==0 ?1:0;};
   if(is_partitioned(v.begin(),v.end(),comp))
      cout<<"\npartitioned!\n";
   else
      cout<<"\nnot partitioned!\n";
}
int main()
{
  vector<int> v = {1,2,3,4,5,6,7};
  auto comp = [](int a){ return a%2==0?1:0;};
  print(v);
  check(v);
  //if(is_partitioned(v.begin(),v.end(),comp))
  //  cout<<"\npartitioned!\n"; 
  //else
  //  cout<<"\nnot partitioned!\n";
  vector<int> sv(v.begin(),v.end());
  partition(v.begin(),v.end(),comp);
  print(v);
  check(v);
  stable_partition(sv.begin(),sv.end(),comp);
  print(sv);
  return 0;
}
