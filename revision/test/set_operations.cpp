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
  vector<int> v2={9,1,7};
  vector<int> r(v1.size()+v2.size());
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  print(v1);
  print(v2);
  auto it = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),r.begin());
  r.resize(it-r.begin());
  print(r);
  cout<<endl<<"******************************"<<endl;
  it = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),r.begin());
  r.resize(it-r.begin());
  print(r);
  r.resize(v1.size()+v2.size());
  cout<<endl<<"******************************"<<endl;
  it = set_difference(v1.begin(),v1.end(), v2.begin(),v2.end(),r.begin());
  r.resize(it-r.begin());
  print(r); 
  r.resize(v1.size()+v2.size());
  cout<<endl<<"******************************"<<endl;
  it = set_symmetric_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),r.begin());
  r.resize(it-r.begin());
  print(r);
  return 0;
}

