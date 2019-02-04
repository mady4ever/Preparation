#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a[]={1,3,30,40,50};
   int b[5];
   replace_if(begin(a),end(a),[](int a){ return a%2==0?true:false;},-1);
   for(auto i: a)
     cout<<i<<"\t";
   return 0;
}

