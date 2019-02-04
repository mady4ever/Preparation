#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v={1,2,3,4,5,6,7};
  auto it = remove_if(v.begin(),v.end(),[](int a){ return a%2==0?1:0;});
  v.resize(it-v.begin());
  for(auto i: v)
   cout<<i<<endl;
  return 0;
}
