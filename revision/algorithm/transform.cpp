#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a[]={10,20,30,40,50};
   int b[5];
   transform(begin(a),end(a),begin(b),[](int a){ return a*a;});
   for(auto i: b)
     cout<<i<<"\t";
   return 0;
}

