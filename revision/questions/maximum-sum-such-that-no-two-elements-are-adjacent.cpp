/*
   https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
   maintain the sum with including and excluding the elementes.
*/
#include<bits/stdc++.h>
using namespace std;
int maxSum(int a[],int s)
{
   int incl = a[0];
   int excl = 0;
   int excl_new = 0;
   for(int i=1;i<s;i++)
   {
      excl_new = max(incl,excl);
      incl = excl + a[i];
      excl = excl_new;
   }
   return max(incl,excl);
}
int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  cout<<maxSum(arr,n);
  return 0;
}
