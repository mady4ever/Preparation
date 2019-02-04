/*
  https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
  Also known as dutch flag algorithm or 3 way partition algorithm.
*/
#include<bits/stdc++.h>
using namespace std;
void dutchFlagAlgo(int a[],int s)
{
  int l=0;
  int m=0;
  int h=s-1;
  while(m<h)
  {
    if(a[m]==0)
    {
      swap(a[l],a[m]);
      l++;
      m++;
    }
    else if(a[m]==2)
    {
      swap(a[m],a[h]);
      h--;
    }
    else 
       m++;
  }
}
int main()
{
  int a[]={2,1,0,1,0,2};
  int s=sizeof(a)/sizeof(a[0]);
  dutchFlagAlgo(a,s);
  for(int i=0;i<s;i++)
  {
    cout<<a[i]<<"\t";
  }
  return 0;
}
