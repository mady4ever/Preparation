#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v = {1,2,3,4,4,5,6,7};
  cout<<count(v.begin(),v.end(),4)<<endl;
  cout<<count_if(v.begin(),v.end(),[](int a){ return a%2==0?1:0;})<<endl;
  return 0;
}
