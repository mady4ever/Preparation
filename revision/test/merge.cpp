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
int main()
{
  vector<int> v1={6,5,4,3,2,1};
  vector<int> v2={9,8,7};
  vector<int> r(v1.size()+v2.size());
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  print(v1);
  print(v2);
  merge(v1.begin(),v1.end(),v2.begin(),v2.end(),r.begin());
  print(r);
  return 0;
}
