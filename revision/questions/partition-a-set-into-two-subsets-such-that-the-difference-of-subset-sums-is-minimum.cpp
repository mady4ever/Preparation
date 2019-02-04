/*
 https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
 similar to partition problem where we try to make any arrangement of set elements causes to be sum=0
 when sum = (total sum) / 2
*/
#include<bits/stdc++.h>
using namespace std;
int subtotalmin(int a[],int s,int i,int sum,int totalSum)
{
   if(i==s-1)
     return abs((totalSum-sum)-sum); // check the abs difference between the two sets.
     //one set is (sum) other set is (total-sum). difference between these should be minimum.
   return min(subtotalmin(a,s,i+1,sum+a[i],totalSum),subtotalmin(a,s,i+1,sum,totalSum));
}
int main()
{
  int a[]={3, 1, 4, 2, 2, 1};
  int s = sizeof(a)/sizeof(a[0]);
  int sum=0;
  for(int i=0;i<s;i++)
    sum+=a[i];
  cout<<subtotalmin(a,s,0,0,sum);
  return 0;
}
