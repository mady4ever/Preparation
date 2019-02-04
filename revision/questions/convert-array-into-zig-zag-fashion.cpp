/*
   https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
   Given an array of DISTINCT elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f.
   for every 1,3,5,7 position gather max form neightbor's (left and right side elements or adjucent elements) and swap the values.
*/
#include<bits/stdc++.h>
using namespace std;
int getMaxIndex(int a[],int s,int index)
{
   if(index >= s)
   {
     int m = max(a[index],a[index-1]);
     if(m == a[index])
       return index;
     else
       return index-1;
   }
   else
   {
     int m = max(max(a[index-1],a[index]), a[index +1]);
     if(m == a[index-1])
        return index-1;
     else if(m == a[index])
        return index;
     else
        return index+1;
   }
}
void zigzag(int a[],int s)
{
   for(int i=1;i<s;i+=2)
   {
     int max_index = getMaxIndex(a,s,i);
     swap(a[i],a[max_index]);
   }
}
int main()
{
  int a[]={1,4,3,2};
  int s= sizeof(a)/sizeof(a[0]);
  zigzag(a,s);
  for(int i=0;i<s;i++)
     cout<<a[i]<<"\t";
  return 0;
}
