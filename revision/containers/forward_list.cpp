#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
  forward_list<int> fl={1,2,3,4,5};
  while(!fl.empty())
  {
    cout<<fl.front()<<"\t";
    fl.pop_front();
  }
  return 0;
}
