/*
 https://www.geeksforgeeks.org/xor-subarray-xors/
 XOR of the number will reset the number if it present at even number of times.
 so, check the requency of the number in an array and check if it's odd then add to the result.
*/
#include<bits/stdc++.h>
using namespace std;
int xorOfSubarrays(int a[],int s)
{
  int res=0;
  for(int i=0;i<s;i++)
  {
    int freq = (i + 1)*(s-i);
    //if(!(freq >> 1 & 1))
    //  res ^= a[i];
    if(freq%2 == 1 )
       res ^= a[i];
  }
  return res;
}
int main()
{
  int a[]={3, 5, 2, 4, 6};
  int s = sizeof(a)/sizeof(a[0]);
  cout<<xorOfSubarrays(a,s);
  return 0;
}
