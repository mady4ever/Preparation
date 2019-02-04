#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a[]={10,20,30,40,50};
   int b[5];
   reverse(begin(a),end(a));
   for(auto i: a)
     cout<<i<<"\t";
   return 0;
}

