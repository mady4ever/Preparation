#include<iostream>
#include<array>
using namespace std;

int main()
{
   array<int,5> a={1,2,3,4,5};
   for(auto i: a)
   {
     cout<<i<<"\t";
   }
   return 0; 
}
