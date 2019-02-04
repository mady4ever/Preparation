#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 4
bool isValid(int mat[M][N], int r, int c)
{
   if(r < 0 || c < 0 || r >=M || c>=N)
   {
      return false;
   }
   if(mat[r][c] == 1)
      return true;
   return false;
}
void path(int mat[M][N] , int r, int c , int v[M][N])
{
   cout<<r<<c<<endl;
   v[r][c] = 1;
   if(r == M -1 && c == N -1)
   {
      cout<<"Path exists";
      return;
   }
   
   //       -1,0
   //
   //  0,-1  0,0  0,+1
   //      
   //        +1,0
   int rr[] = {0,0,0,-1,1};
   int cc[] = {0,1,-1,0,0};
   for(int i=0;i<M;i++)
   {
     if(isValid(mat,r+rr[i],c+cc[i]) && v[r+rr[i]][c+cc[i]] == 0)
        path(mat, r+rr[i], c+cc[i],v);
   }
}
int main()
{
  int mat[M][N] ={{1,0,0,0},
                  {1,0,0,0},
		  {1,0,0,0},
		  {1,1,1,1}};
  int v[M][N] ={{0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,0}};
  path(mat,0,0,v); 
  return 0;
}
