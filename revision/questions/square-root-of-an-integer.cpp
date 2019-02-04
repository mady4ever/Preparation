/*
  do binary search.
*/
#include<bits/stdc++.h>
using namespace std;
int binary_search_num(int num)
{
   int l = 2;
   int h = num;
   int mid=0;
   while(l < h )
   { 
     mid = (l + h)/2;
     if(mid*mid == num)
       return mid;
     if(mid*mid < num)
       l = mid + 1;
     else
       h = mid -1;
   }
   return mid -1;
}
int main()
{
  cout<<binary_search_num(4);
  return 0;
}
