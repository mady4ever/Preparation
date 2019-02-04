#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  vector<int> v = {1,2,3,4,5};
  vector<int> v2(v.begin(),v.end());
  if(equal(v.begin(),v.end(),v2.begin(), [](int a,int b){ return a==b?1:0;}))
  {
     cout<<"both are equal";
  }
  return 0;
}
