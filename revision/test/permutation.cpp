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
  vector<int> v={1,2,3,4,5,6,7};
  vector<int> v1(v.begin(),v.end());
  reverse(v1.begin(),v1.end());
  if(is_permutation(v.begin(),v.end(),v1.begin()))
  {
     cout<<"It's permutation"<<endl;
  }
  cout<<endl;
  vector<int> v2 = {1,2,3};
  do
  {
    print(v2);
  }while(next_permutation(v2.begin(),v2.end()));

  cout<<"\n++++++++++++ \n";

  do
  {
    print(v2);
  }while(prev_permutation(v2.begin(),v2.end()));
  return 0;
}
