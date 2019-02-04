#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v={1,2,3,4,5};
  vector<int> v1(v.begin(),v.end());
  auto p = mismatch(v.begin(),v.end(),v1.begin());
  cout<<*p.first<<*p.second<<endl;
  v1.push_back(10);
  p = mismatch(v.begin(),v.end(),v1.begin());
  cout<<*p.first<<*p.second<<endl;
  return 0;
}
