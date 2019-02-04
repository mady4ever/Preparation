/*
  https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
  
  0 1 1  1
  1 2 3  4
  1 3 6  10
  1 4 10 20
*/
#include<bits/stdc++.h>
using namespace std;
int countpathsrecurse(int m,int n)
{
   if(m==1 || n==1)
    return 1;
   return countpathsrecurse(m-1,n) + countpathsrecurse(m,n-1);
}
int countpaths(int m,int n)
{
  int mat[m][n];
  for(int i=0;i<m;i++)
    mat[i][0] = 1;
  for(int i=0;i<n;i++)
    mat[0][i] = 1;
  for(int i=1;i<m;i++)
  {
    for(int j=1;j<n;j++)
    {
       mat[i][j] = mat[i-1][j] + mat[i][j-1];
    }
  }
  return mat[m-1][n-1];
}
int main()
{
  cout<<countpaths(3,3);
  cout<<endl;
  cout<<countpathsrecurse(3,3);
  return 0;
}
