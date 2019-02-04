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
  vector<int> v={1,10,9,2,8,3,3,10};
  //sort(v.begin(),v.end());
  stable_sort(v.begin(),v.end());
  print(v);   
  return 0;
}
