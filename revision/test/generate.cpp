#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int rnd=0;
auto gen = [](){return ++rnd;};
int main()
{
  vector<int> v(10);
  generate(v.begin(),v.end(),gen);
  for(auto i: v)
   cout<<i<<endl;
  cout<<endl;
  generate_n(v.begin(),5,gen);
  for(auto i: v)
    cout<<i<<endl;
  return 0;
}
