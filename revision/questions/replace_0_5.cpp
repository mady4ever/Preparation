/*
  https://www.geeksforgeeks.org/replace-0-5-input-integer/
*/
#include<bits/stdc++.h>
using namespace std;
int replace0by5(int num)
{
   if(num == 0 ) return 0;
   int digit = num % 10;
   if(digit == 0)
     digit = 5;
   return digit + 10*replace0by5(num/10);
}
int main()
{
  cout<<replace0by5(100);
  return 0;
}
