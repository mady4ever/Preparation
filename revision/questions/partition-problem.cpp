/*
  https://www.geeksforgeeks.org/partition-problem-dp-18/
*/
#include<bits/stdc++.h>
using namespace std;
bool isSum(int a[],int s,int index,int sum)
{
  if(index==s && sum==0)
    return true;
  if(index>s && sum!=0)
    return false;
  if(a[index]>sum)
    return isSum(a,s,index+1,sum);
  return isSum(a,s,index+1,sum) || isSum(a,s,index+1,sum-a[index]);
}
int main()
{
  int a[]={1,5,12,4,1};
  int s=sizeof(a)/sizeof(a[0]);
  int sum=0;
  for(int i=0;i<s;i++)
   sum+=a[i];
  cout<<isSum(a,s,0,sum/2);
  return 0;
}
