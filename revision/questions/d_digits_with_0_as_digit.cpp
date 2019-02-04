/*
  https://www.geeksforgeeks.org/count-d-digit-positive-integers-with-0-as-a-digit/
  9 * (10^d-1 - 9^d-1);
*/
#include<bits/stdc++.h>
using namespace std;
int digits(int d)
{
   return 9*(pow(10,d-1)-pow(9,d-1));
}
int main()
{
  cout<<digits(3);
  return 0;
}
