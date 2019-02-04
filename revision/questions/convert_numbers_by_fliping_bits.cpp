/*
  https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
*/
#include<bits/stdc++.h>
using namespace std;
int counts(int a,int b)
{
  int c = a ^ b;
  int count=0;
  while(c>0)
  {
    count+=(c & 1);
    c>>=1;
  }
  return count;
}
int main()
{
  cout<<counts(1,5);
  return 0;
}
