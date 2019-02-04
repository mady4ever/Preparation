/*
  https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/
  1] sort the number
  2] set the one element comman
  3] check from left and right side if sum is greater then decrease from right hand side.
  4] if sum is smaller then increase from left hand side.
  5] increament count.
*/
#include<bits/stdc++.h>
using namespace std;
int counttripletes(int a[],int s, int sum)
{
  sort(a,a+s);//O(nLog(n))
  int ans=0;
  for(int i=0;i<s-2;i++)
  {
    int j = i + 1;
    int k = s - 1;
    while(j<k)
    {
       if(a[i]+a[j]+a[k] >= sum)
       {
          k--;
       }
       else
       {
          ans+=(k-j);
          j++;
       }
    }
  }
  return ans;
}
int main()
{
  int arr[] = {-2, 0, 1, 3};
  int sum = 2;
  int s = sizeof(arr)/sizeof(arr[0]);
  cout<<counttripletes(arr,s,sum);
  return 0;
}
