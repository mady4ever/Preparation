/*
  if matrix ith raw or col is 1 then make all ith raw and col 1's.
  https://www.geeksforgeeks.org/a-boolean-matrix-question/
*/
#include<bits/stdc++.h>
using namespace std;
#define M 4  // considering square matrix only.
void matsetraw(int mat[][M],int r)
{
     for(int i=0;i<M;i++)
       mat[r][i] = 1;
}
void matsetcol(int mat[][M],int c)
{
    for(int i=0;i<M;i++)
       mat[i][c] = 1;
}
void makeOnce(int mat[M][M])
{
   vector<bool> raw(M,false);
   vector<bool> col(M,false); 
   for(int i=0;i<M;i++)
   {
     for(int j=0;j<M;j++)
     { 
       if(mat[i][j] == 1)
       {
          raw[i] = true;
          col[j] = true;
       }
     }
   }
   for(int i=0;i<M;i++)
   {
      for(int j=0;j<M;j++)
      {
        if(raw[i] == true && col[j] == true)
        {
           matsetraw(mat,i);
           matsetcol(mat,j);
        }
      }
   }
}
void printmat(int mat[][M])
{
    for(int i=0;i<M;i++)
   {
     for(int j=0;j<M;j++)
     {
        cout<<mat[i][j]<<"\t";
     }
     cout<<endl;
   }
}
int main()
{
  int mat[][M] = {{1,0,0,1},
                  {0,0,1,0},
                  {0,0,0,0},
                  {0,0,0,0}};
  makeOnce(mat);
  printmat(mat);
  return 0;
}
