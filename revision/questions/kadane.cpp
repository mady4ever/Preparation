#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int s)
{
   int sum = 0;
   int max_sum = 0;
   for(int i=0;i<s;i++)
   {
     sum +=a[i];
     if(sum > max_sum)
       max_sum = sum;
     if(a[i] < 0)
     {
       max_sum = max(sum,max_sum);
       sum = 0;
     }
   }
   return max_sum;
}
int kadane2(int a[], int s)
{
   int sum = a[0];
   int max_sum = a[0];
   for(int i=1;i<s;i++)
   {
     sum = max(a[i],a[i]+sum);
     max_sum = max(sum,max_sum);
   }
   return max_sum;
}
int main()
{
  int a[] = {-1,-2,-1,5,6,-7};
  int s = sizeof(a)/sizeof(a[0]);
  cout<<kadane2(a,s);
  return 0;
}
