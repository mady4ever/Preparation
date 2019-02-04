#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(vector<int> i)
{
  for(auto ii:i)
   cout<<ii<<"\t";
  cout<<endl;
}
int main()
{
  vector<int> v={1,2,3,4,5};
  replace(v.begin(),v.end(),2,200);
  for(auto i: v)
   cout<<i<<"\t";
  cout<<endl;
  replace_if(v.begin(),v.end(),[](int a){ return a%2==0?1:0;},0);
  for(auto i: v)
   cout<<i<<"\t";
  vector<int> v1(v.size());
  cout<<endl;
  replace_copy(v.begin(),v.end(),v1.begin(),0,100);
  for(auto i: v1)
   cout<<i<<"\t";
  replace_copy_if(v.begin(),v.end(),v1.begin(),[](int a){ return 1;},0);
  print(v1);
  return 0;
}
