/*
  https://www.geeksforgeeks.org/number-of-paths-with-exactly-k-coins/
*/
#include<bits/stdc++.h>
using namespace std;
#define M 3
int ways(int mat[][M],int m,int n,int sum)
{
  if(m < 0 || n < 0) return 0;
  if(m==0 && n == 0) return (sum-mat[m][n])==0;
  return ways(mat,m-1,n,sum-mat[m][n]) + ways(mat,m,n-1,sum-mat[m][n]);
}
int main()
{
  int k = 12; 
  int mat[3][3] = { {1, 2, 3}, 
                      {4, 6, 5}, 
                      {3, 2, 1}}; 
  cout<<ways(mat,M-1,M-1,k);
  return 0;
}
