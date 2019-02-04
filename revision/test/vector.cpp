#include<iostream>
#include<vector>
using namespace std;
int main()
{
  vector<int> mvec;
  for(int i=0;i<10;i++)
     mvec.push_back(i*10);  
  for(auto i:mvec)
     cout<<i<<"\t";
  cout<<endl;
  for(vector<int>::iterator it=mvec.begin(); it!=mvec.end();it++)
  {
       cout<<*it<<"\t";
  }
  //while(mvec.size()>0)
  //  mvec.pop_back();
  while(!mvec.empty())
  {
    cout<<"\nFront: "<<mvec.front()<<endl;
    cout<<mvec.back()<<"\t";
    mvec.pop_back();
  }
  mvec.clear();
  return 0;
}
