/*
   https://www.geeksforgeeks.org/tiling-problem/
   basically it's a dp problem 
   base cases are 0 = 1
                  1 = 1
                  2 = (0) + (1) = 1 + 1 = 2 
                  3 = (2) + (1) = 2 + 1 = 3
*/
#include<bits/stdc++.h>
using namespace std;
int tilingCount(int num)
{
  int a[num];//={0};
  a[0] = 1;
  a[1] = 1;
  for(int i=2;i<num;i++)
    a[i] = a[i-1] + a[i-2];
  return a[num-1];
}
int main()
{
  cout<<tilingCount(5);
  return 0;
}
