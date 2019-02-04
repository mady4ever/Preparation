#include<iostream>
#include<deque>
using namespace std;
int main()
{
  deque<int> dq;
  for(int i=0;i<10;i++)
  { 
    dq.push_back(i);
    cout<<"back :"<<dq.back(); 
    dq.push_front(2*i);
    cout<<"front :"<<dq.front();
    cout<<endl;
    cout<<dq.size()<<endl;
  }
  for(auto i: dq)
  {
     cout<<i<<"\t";
  }
  dq.clear();
  cout<<"\nsize :"<<dq.size();
  return 0;
}
