#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
   vector<int> v = {1,2,3,4,5,6,7,8};
   if(find(v.begin(),v.end(),5) != v.end())
   {
      cout<<"found object\n";
   }
   else
   {
      cout<<"not found\n";
   }
   if(find_if(v.begin(),v.end(),[](int a){ return a%2==0?1:0;}) != v.end())
   {
       cout<<"found even in the vector\n";
   }
   return 0;
}
