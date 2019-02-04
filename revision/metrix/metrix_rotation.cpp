#include<bits/stdc++.h>
using namespace std;
#define M 4
void swapa(int a, int b)
{
     a = a ^ b;
     b = a ^ b;
     a = a ^ b;
}
void transpose(int mat[M][M])
{
   for(int r=0;r<M;r++)
   { 
     for(int c=r;c<M;c++)
     {
       swap(mat[r][c],mat[c][r]);
     }
   }
}
void swap_cols(int mat[M][M], int c1, int c2)
{
  for(int r=0;r<M;r++)
  {
     swap(mat[r][c1],mat[r][c2]);
  }
}
void printmat(int mat[M][M])
{
   for(int i=0;i<M;i++)
   {
     for(int j=0;j<M;j++)
     {
        cout<<mat[i][j]<<"\t";
     }
     cout<<endl;
   }
   cout<<endl;
}
void rotatemat(int mat[M][M])
{
   transpose(mat);
   swap_cols(mat,0,3);
   swap_cols(mat,1,2);
}
int main()
{
  int mat[][M]={{1,2,3,4},
               {5,6,7,8},
	       {9,10,11,12},
	       {13,14,15,16}};
  printmat(mat);
  rotatemat(mat);
  printmat(mat);
  return 0;
}
