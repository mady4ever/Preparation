#include<list>
#include<iostream>
using namespace std;
int main()
{
   list<int> l = {5,4,3,2,1};
   for(auto i: l)
    cout<<i<<"\t";
   return 0;
}
