/*
  https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/
#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int s)
{
  int c_sum = 0;
  int m_sum = 0;
  for(int i=0;i<s;i++)
  { 
    c_sum+=a[i];
    m_sum = max(m_sum, c_sum);
    if(c_sum<0)
     c_sum = 0;
  }
  return m_sum;
}
int main()
{
  int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
  int n = sizeof(a)/sizeof(a[0]);
  cout<<kadane(a,n); 
  return 0;
}
