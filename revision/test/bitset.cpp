#include<iostream>
#include<vector>
#include<bitset>
#include<string>
using namespace std;
int main()
{
  bitset<5> bs(string("10101"));
  cout<<bs<<endl;
  cout<<bs.test(1)<<endl;
  cout<<bs.any()<<endl;
  cout<<bs.count()<<endl;
  cout<<bs.none()<<endl;
  cout<<bs.flip()<<endl;
  cout<<bs.to_ulong()<<endl;
  cout<<bs.all()<<endl;
  return 0;
}
