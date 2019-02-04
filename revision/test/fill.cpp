#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v(10);
  fill(v.begin(),v.end(),10);
  for(auto i: v)
   cout<<i<<endl;
  return 0;
}
