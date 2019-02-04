/*
  1] use user define comparator which check the index of the values and compare it.
  https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/
*/
#include<bits/stdc++.h>
using namespace std;
int indexOfValue(int a[],int s,int x)
{
  for(int i=0;i<s;i++)
  {
    if(a[i]==x)
      return i;
  }
  return x;
}
void sortWithAnotherArr(int a[],int a_s,int b[],int b_s)
{
  auto comp=[b,b_s](int aa,int bb){ return indexOfValue(b,b_s,aa)<indexOfValue(b,b_s,bb);};
  sort(a,a+a_s,comp);
  for(int i=0;i<a_s;i++)
  {
     cout<<a[i]<<"\t";
  } 
}
int main()
{
  int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}; 
  int A2[] = {2, 1, 8, 3}; 
  int m = sizeof(A1)/sizeof(A1[0]); 
  int n = sizeof(A2)/sizeof(A2[0]); 
  sortWithAnotherArr(A1,m,A2,n);
  return 0;
}
