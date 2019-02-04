#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  vector<int> v={2,4,6,8};
  if(all_of(v.begin(),v.end(),[](int a){ return a%2;}))
  {
     cout<<"all Even\n";
  }
  else
  {
     cout<<"all odds\n";
  }
  if(any_of(v.begin(),v.end(),[](int a){ return a%2;}))
  {
    cout<<"any of is true\n";
  }
  if(none_of(v.begin(),v.end(),[](int a){ return a%2;}))
  {
    cout<<"none of is true\n";
  }
  return 0;
}
