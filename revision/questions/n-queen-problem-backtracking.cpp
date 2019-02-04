/*
  best example of backtracking.
  1] Try to keep queen in every columns one by one.
  2] If column == N-1 // i.e. max queens placed on board return true;
  3] Check for every raw and keep queen at place and try to put queen at next place. if next queen place leads to the solution then place it.
  https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/ 
*/
#include<bits/stdc++.h>
using namespace std;
#define N 5
bool isSafe2(int board[N][N],int row, int col)
{
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true;
}
bool isSafe(int mat[N][N],int r,int c)
{
   //check in raw;
   for(int i=0;i<N;i++)
   {
      if(mat[r][i]==1)
        return false;
   }
   //check in col;
   for(int i=0;i<N;i++)
   {
      if(mat[i][c]==1)
        return false;
   }
   //check in left diagonal.
   int i=r,j=c;
   while(i<=N-1 && j<=N-1)
   {
      if(mat[i][j]==1)
        return false;
      i++;
      j++;
   }
   i=r;
   j=c;
   while(i>=0 && j>=0)
   {
      if(mat[i][j]==1)
        return false;
      i--;
      j--;
   }
   //check in right diagonal.
   i=r;
   j=c;
   while(i<=N-1 && j>=0)
   {  //i++ j--
     if(mat[i][j]==1)
       return false;
     i++;
     j--;      
   }
   i=r;
   j=c;
   while(i>=0 && j<=N-1)
   {
     if(mat[i][j]==1)
       return false;
     i--;
     j++;
   }
   //cout<<"returning true : "<<r<<"\t"<<c<<endl; 
   return true;
}
bool solveQueen(int mat[N][N],int col)
{
  if(col>= N-1)
    return true;
  
  for(int r=0;r<N;r++)
  {
    if(isSafe2(mat,r,col))
    {
      mat[r][col] = 1;

      if(solveQueen(mat,col+1))
        return true;

      mat[r][col] = 0;
    }
  }
  return false;
}
void printQueen(int mat[N][N])
{
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      cout<<mat[i][j]<<"\t";
    }
      cout<<endl;
  }
}
int main()
{
  int mat[N][N]={{0,0,0,0,0},
                 {0,0,0,0,0},
		 {0,0,0,0,0},
		 {0,0,0,0,0}};
  //int mat[N][N]={0};
  if(solveQueen(mat,2))
    printQueen(mat); 
  return 0;
}
