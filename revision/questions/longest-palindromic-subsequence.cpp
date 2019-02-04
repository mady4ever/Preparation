/*
  https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
*/
#include<bits/stdc++.h>
using namespace std;
int pelindromic(string a,int l,int r)
{
  //cout<<l<<"\t"<<r<<endl;
  //if(l>r) return 0;
  if(l==r)
   return 1;
  if((l+1 == r || l == r-1)&& a[l]==a[r])
    return 2;
  else if(a[l]==a[r])
    return 2 + pelindromic(a,l+1,r-1);
  else
    return max(pelindromic(a,l+1,r),pelindromic(a,l,r-1));
}
int main()
{
  //GEEKS FOR GEEKS
  cout<<pelindromic("abcd",0,4);
  return 0;
}
