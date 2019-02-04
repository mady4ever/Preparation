/*
  https://www.geeksforgeeks.org/find-water-in-a-glass/
  pascal's triangle.
*/
// Program to find the amount of water in j-th glass 
// of i-th row 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Returns the amount of water in jth glass of ith row 
float findWater(int i, int j, float X) 
{ 
	// A row number i has maximum i columns. So input 
	// column number must be less than i 
	if (j > i) 
	{ 
		printf("Incorrect Inputn"); 
		exit(0); 
	} 

	// There will be i*(i+1)/2 glasses till ith row 
	// (including ith row) 
	float glass[i * (i + 1) / 2]; 

	// Initialize all glasses as empty 
	memset(glass, 0, sizeof(glass)); 

	// Put all water in first glass 
	int index = 0; 
	glass[index] = X; 

	// Now let the water flow to the downward glasses 
	// till the row number is less than or/ equal to i (given row) 
	// correction : X can be zero for side glasses as they have lower rate to fill 
	for (int row = 1; row <= i ; ++row) 
	{ 
		// Fill glasses in a given row. Number of 
		// columns in a row is equal to row number 
		for (int col = 1; col <= row; ++col, ++index) 
		{ 
			// Get the water from current glass 
			X = glass[index]; 

			// Keep the amount less than or equal to 
			// capacity in current glass 
			glass[index] = (X >= 1.0f) ? 1.0f : X; 

			// Get the remaining amount 
			X = (X >= 1.0f) ? (X - 1) : 0.0f; 

			// Distribute the remaining amount to 
			// the down two glasses 
			glass[index + row] += X / 2; 
			glass[index + row + 1] += X / 2; 
		} 
	} 

	// The index of jth glass in ith row will 
	// be i*(i-1)/2 + j - 1 
	return glass[i*(i-1)/2 + j - 1]; 
} 

// Driver program to test above function 
int main() 
{ 
	int i = 2, j = 2; 
	float X = 2.0; // Total amount of water 

	printf("Amount of water in jth glass of ith row is: %f", 
			findWater(i, j, X)); 

	return 0; 
} 

