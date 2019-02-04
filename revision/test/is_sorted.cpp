#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(vector<int> v)
{
  for(auto i: v)
  {
    cout<<i<<"\t";
  }
   cout<<endl;
}
int main()
{
  vector<int> v={4,1,3,2};
  do
  {
     next_permutation(v.begin(),v.end());
     print(v);
  }while(!is_sorted(v.begin(),v.end()));
  return 0;
}
