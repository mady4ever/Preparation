#include<iostream>
#include<set>
using namespace std;

int main()
{
  auto comp =[](int a,int b){ return a>b?1:0;};
  set<int,decltype(comp)> s(comp);
  for(int i=0;i<10;i++)
  {
    s.insert(i*10);
  }
  cout<<endl;
  for(auto i: s)
  {
    cout<<i<<"\t";
  }
  cout<<endl<<*s.find(30)<<endl;
  cout<<s.count(30)<<"\n";
  s.clear();
  return 0;
}
