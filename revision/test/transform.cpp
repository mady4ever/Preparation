#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v={1,2,3,4,5,6};
  transform(v.begin(),v.end(),v.begin(),[](int a){return a*a;});
  for(auto i: v)
  {
    cout<<i<<"\t";
  }
  return 0;
}
