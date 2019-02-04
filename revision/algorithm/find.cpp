#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int a[]={10,20,30,40,50};
   auto it = find(begin(a),end(a),10);
   cout<<*it;
   auto itt = find_if(begin(a),end(a),[](int a){ if(a==10) return true;});
   cout<<*itt;
   return 0;
}
