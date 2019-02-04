#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> vi={1,2,3,4,5};
  for_each(vi.begin(),vi.end(),[](int a){ cout<<a*a<<"\t";});
  for(auto i: vi)
  {
     cout<<i<<"\t";
  }
  return 0;
}
