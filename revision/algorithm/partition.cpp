#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a[]={1,2,3,4,5};
   int b[5];
   auto it = partition(begin(a),end(a),[](int a){ return a%2==0?true:false;});
   
   for(auto i: a)
     cout<<i<<"\t";
   return 0;
}

