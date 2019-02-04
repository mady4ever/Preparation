#include<iostream>
#include<array>
using namespace std;
int main()
{
  array<int,10> marray;
  marray.fill(10);
  for(auto i:marray)
  {
    cout<<i<<"\t";
  }
  return 0;
}
