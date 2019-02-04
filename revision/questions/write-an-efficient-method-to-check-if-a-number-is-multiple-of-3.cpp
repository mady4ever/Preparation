/*
  1] if number is multiple of 3 then cound of digits is divisible by 3.
  2] count of bits at odd position minus count of digits at even count if result recersively gives one then yes else no.
  https://www.geeksforgeeks.org/write-an-efficient-method-to-check-if-a-number-is-multiple-of-3/
*/
#include<bits/stdc++.h>
using namespace std;
bool numberdivby3(int num)
{
  int odd =0 ;
  int even = 0;
  if(num < 0)
    num= abs(num);
  if(num==0) return true;
  if(num==1) return false;
  while(num)
  {
    if(num & 1)
      odd++;
    num>>=1;
    if(num & 1)
      even++;
    num>>=1;
  }
  return numberdivby3(abs(odd-even));
}
int main()
{
  cout<<numberdivby3(13);
  return 0;
}
