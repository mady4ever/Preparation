/*
   https://www.geeksforgeeks.org/reverse-an-array-upto-a-given-position/
*/
#include<bits/stdc++.h>
using namespace std;
void reversearray(int a[],int s,int k)
{
  int i=0;
  int j=k;
  while(i<j)
  {
     swap(a[i],a[j]);
     i++;
     j--;
  }
}
int main()
{
  int a[] = {1, 2, 3, 4, 5, 6}; 
  int n = sizeof(a) / sizeof(int), k = 4;
  reversearray(a,n,k);
  for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";
  return 0;
}
