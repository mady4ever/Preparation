#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v = {1,9,2,8,3,7,4,6};
  auto it = minmax_element(v.begin(),v.end());
  cout<<*it.first<<" "<<*it.second<<endl;
  return 0;
}
