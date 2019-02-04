#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a[]={10,20,30,40,50};
   int b[5];
   replace(begin(a),end(a),10,20);
   for(auto i: a)
     cout<<i<<"\t";
   return 0;
}

