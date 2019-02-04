/*
  https://www.geeksforgeeks.org/find-subarray-with-given-sum/
  maintaining two values l and r
  and expand to right in case of sum of elements is less and
  shrink from left while sum is greater.
*/
#include<bits/stdc++.h>
using namespace std;
void checkForSubArraySum(int a[],int s,int sum)
{
   //int l=0;
   //int r=0;
   //int c_sum = 0;
   //while((l<s || r<s || l < r))
   //{
   //   c_sum+=a[r];
   //   if(c_sum <= sum)
   //   {
   //      r++;
   //   }
   //   else if(c_sum > sum)
   //   {
   //       while(c_sum > sum && l < r)
   //       {
   //          c_sum -=a[l];
   //          l++;
   //       }
   //       if(c_sum==sum)
   //       {
   //         cout<<l<<"\t"<<r<<endl;
   //         break;
   //       }
   //   }
   //   else //found range.
   //   {
   //       cout<<l<<"\t"<<r<<endl;
   //       break;
   //   }
   //   if(l>r) break;
   //   cout<<l<<"\t"<<r<<"\t"<<c_sum<<endl;
   //}
   int c_sum=a[0];
   int start=0;
   for(int i=1;i<=s;i++)
   {
     //if(c_sum > sum)
     //{
        while(c_sum > sum && start < i-1)
        {
          c_sum = c_sum - a[start];
          start++;
        }
     //}
     if(c_sum == sum)
     { 
        cout<<start<<"\t"<<i-1<<endl;
        return;
     }
     if(i<s)
       c_sum+=a[i];
   }
}
int main()
{
  int arr[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  int sum = 23;
  checkForSubArraySum(arr,n,sum);
  return 0;
}
