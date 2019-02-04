#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v={1,2,3,4,5,6};
  reverse(v.begin(),v.end());
  for(auto i: v)
    cout<<i<<endl;
  return 0;
}
