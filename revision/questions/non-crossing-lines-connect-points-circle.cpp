/*
  its finding out the n/2th catalan number.
  https://www.geeksforgeeks.org/non-crossing-lines-connect-points-circle/
*/
#include<bits/stdc++.h>
using namespace std;
int catalan(int num)
{
  int cat[num+1];
  
  for(int i=0;i<=num;i++)
    cat[i] = 0;
  cat[0]=1;
  cat[1]=1;
  for(int i=2;i<=num;i++)
  {
     for(int j=0;j<i;j++)
       cat[i]+=cat[j]*cat[i-j-1];
  }
  return cat[num];
}
int numberOfLines(int num)
{
    // Throw error if n is odd 
   if (num & 1) 
   { 
      cout << "Invalid"; 
      return 0; 
   } 
   return catalan(num/2);
} 
int main()
{
  cout<<numberOfLines(4);
  return 0;
}
