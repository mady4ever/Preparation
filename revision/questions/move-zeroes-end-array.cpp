/*
   https://www.geeksforgeeks.org/move-zeroes-end-array/
*/
#include<bits/stdc++.h>
using namespace std;
void moveZeros(int a[],int n)
{
   int j=0;
   for(int i=0;i<n;i++)
   {
     if(a[i]!=0)
     {
       swap(a[i],a[j++]);
     }
   }
   for(int i=0;i<n;i++)
   {
     cout<<a[i]<<"\t";
   }
}
int main()
{
  int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  moveZeros(arr,n);
  return 0;
}
