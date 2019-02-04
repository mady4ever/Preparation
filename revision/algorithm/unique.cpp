#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
   int a[]={1,1,3,3,50};
   vector<int> b(a,a+5);
   for(auto i: b)
    cout<<i<<"\t";
   auto it = unique(b.begin(),b.end());
   b.resize(it-b.begin());
   cout<<"\n size:"<<b.size()<<"\n";
   for(auto i: b)
     cout<<i<<"\t";
   return 0;
}

