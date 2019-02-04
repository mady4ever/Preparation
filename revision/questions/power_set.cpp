/*
 Power Set: Write a method to return all subsets of a set.
*/
#include<bits/stdc++.h>
using namespace std;
void convert_int_to_set(int a[],int s,int i)
{
  int index =0;
  while(i)
  {
    if((i & 1) == 1)
      cout<<a[index]<<"\t";
    index++;
    i = i>>1;
  }
  cout<<endl;
}
int power_set(int a[], int s)
{
  int p = 1<<s; // 2 ^ 3 possible numbers in set
  for(int i=0;i<p;i++)
  {
    convert_int_to_set(a,s,i);
  }
}
int main()
{
  int a[]={1,2,3};
  int s = sizeof(a)/sizeof(a[0]);
  power_set(a,s);
  return 0;
}
