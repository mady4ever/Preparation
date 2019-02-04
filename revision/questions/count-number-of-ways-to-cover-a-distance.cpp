/*
  https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
  
*/
#include<bits/stdc++.h>
using namespace std;
int count_ways(int n)
{
  int a[n];
  a[0]=1;
  a[1]=1;
  a[2]=2;
  for(int i=3;i<n;i++)
  {
    a[i] = a[i-1] + a[i-2] + a[i-3];
  }
  return a[n-1];
}
int main()
{
  cout<<count_ways(4+1);
  return 0;
}
