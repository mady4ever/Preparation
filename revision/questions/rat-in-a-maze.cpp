/*
   https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
*/
/* C/C++ program to solve Rat in a Maze problem using 
backtracking */
#include<stdio.h> 

// Maze size 
#define N 4 

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]); 

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N]) 
{ 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
			printf(" %d ", sol[i][j]); 
		printf("\n"); 
	} 
} 

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y) 
{ 
	// if (x,y outside maze) return false 
	if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
		return true; 

	return false; 
} 

/* This function solves the Maze problem using Backtracking. It mainly 
uses solveMazeUtil() to solve the problem. It returns false if no 
path is possible, otherwise return true and prints the path in the 
form of 1s. Please note that there may be more than one solutions, 
this function prints one of the feasible solutions.*/
bool solveMaze(int maze[N][N]) 
{ 
	int sol[N][N] = { {0, 0, 0, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0} 
	}; 

	if(solveMazeUtil(maze, 0, 0, sol) == false) 
	{ 
		printf("Solution doesn't exist"); 
		return false; 
	} 

	printSolution(sol); 
	return true; 
} 

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) 
{ 
	// if (x,y is goal) return true 
	if(x == N-1 && y == N-1) 
	{ 
		sol[x][y] = 1; 
		return true; 
	} 

	// Check if maze[x][y] is valid 
	if(isSafe(maze, x, y) == true) 
	{ 
		// mark x,y as part of solution path 
		sol[x][y] = 1; 

		/* Move forward in x direction */
		if (solveMazeUtil(maze, x+1, y, sol) == true) 
			return true; 

		/* If moving in x direction doesn't give solution then 
		Move down in y direction */
		if (solveMazeUtil(maze, x, y+1, sol) == true) 
			return true; 

		/* If none of the above movements work then BACKTRACK: 
			unmark x,y as part of solution path */
		sol[x][y] = 0; 
		return false; 
	} 

	return false; 
}
bool solveMazeOneUtil(int mat[N][N],int r,int c,int sol[N][N])
{
  if(r==N-1 && c == N-1)
  {
    printSolution(sol);
    return true;
  }
  int rr[]={0,1};
  int cc[]={1,0};
  for(int i=0;i<2;i++)
  {
    int x = rr[i] + r;
    int y = cc[i] + c;
    if(isSafe(mat,x,y))
    {
       sol[x][y] = 1;
       if(solveMazeOneUtil(mat,x,y,sol))
         return true;
       sol[x][y] = 0;
    } 
  }
  return false;
}
void solveMazeOne(int mat[N][N])
{
   //int sol[N][N]={0,0};
   //if(solveMazeOneUtil(mat,0,0))
   int sol[N][N] = { {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
        };
   solveMazeOneUtil(mat,0,0,sol);
}
// driver program to test above function 
int main() 
{ 
	int maze[N][N] = { {1, 0, 0, 0}, 
		{1, 1, 0, 1}, 
		{0, 1, 0, 0}, 
		{1, 1, 1, 1} 
	}; 

	//solveMaze(maze); 
        solveMazeOne(maze);
	return 0; 
} 

