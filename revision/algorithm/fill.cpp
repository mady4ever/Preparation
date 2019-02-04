#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a[]={10,20,30,40,50};
   int b[5];
   fill(begin(b),end(b),5);
   for(auto i: b)
     cout<<i<<"\t";
   return 0;
}

