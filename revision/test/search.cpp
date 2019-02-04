#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> v={1,2,3,4,5,5,6,7,8};
  vector<int> v1={3,4,5};
  auto it = search(v.begin(),v.end(),v1.begin(),v1.end());
  if(it != v.end())
  {
    cout<<"found match at position"<<it-v.begin()<<endl;
  }
  it = search_n(v.begin(),v.end(),2,5);
  if(it != v.end())
  {
    cout<<"found two 5's at "<<it-v.begin();
  }
  return 0;
}
