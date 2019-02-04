#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;
void print(vector<int> v)
{
  for(auto i: v)
   cout<<i<<"\t";
  cout<<endl;
}
int main()
{
  vector<int> v = {1,9,2,8,3,7,5,6};
  sort(v.begin(),v.end());
  print(v);
  auto lit = lower_bound(v.begin(),v.end(),3);
  cout<<"lower bound "<<lit-v.begin()<<endl;
  auto uit = upper_bound(v.begin(), v.end(),3);
  cout<<"upper bound "<<uit-v.begin()<<endl; 
  return 0;
}
