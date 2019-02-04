/*
  https://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/
*/
#include<bits/stdc++.h>
using namespace std;
bool isPair(int a[],int s, int x)
{
  unordered_map<int,int> mp;
  for(int i=0;i<s;i++)
  {
     if(mp.count(x/a[i]) > 0)
        return true;
     else
     {
       mp[a[i]] = 1;
     }
  }
  return false;
}
int main()
{
  int a[] = {20,10,400,40};
  int s = sizeof(a)/sizeof(a[0]);
  cout<<isPair(a,s,100);
  return 0;
}
