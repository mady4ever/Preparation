/*
  https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
*/
#include<bits/stdc++.h>
using namespace std;
int getSum(int bit[], int index)
{
   index++; // higher index by one.
   int sum = 0;
   while(index > 0)
   {
     sum += bit[index];
     index-= index & (-index); // reset the last bit.
   }
   return sum;
}
void updateBIT(int bit[], int n, int index, int v)
{
   index++; // higher the index by one.
   while(index < n)
   {
     bit[index]+=v;
     index+=index & (-index);
   }
}
int* constructBIT(int a[],int n)
{
   int *bit = new int[n];
   for(int i=0;i<n;i++)
      bit[i] = 0;
   for(int i=0;i<n;i++)
   {
     updateBIT(bit,n,i,a[i]);
   }
   return bit;
}
int getRSum(int bit[], int s,int e)
{
   return getSum(bit,e) - getSum(bit,s-1);
}
int main()
{
  int a[]={2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
  int s = sizeof(a)/sizeof(a[0]);
  int *bit = constructBIT(a,s);
  cout<<getRSum(bit,1,2); 
  return 0;
}
