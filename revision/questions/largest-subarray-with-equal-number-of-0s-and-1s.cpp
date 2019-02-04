/*
  convert problem to largets sub array with zero sum.
*/
// A O(n) program to find the largest subarray 
// with equal number of 0s and 1s 

#include <stdio.h> 
#include <stdlib.h> 

// A utility function to get maximum of two 
// integers 

int max(int a, int b) { return a>b? a: b; } 

// This function Prints the starting and ending 
// indexes of the largest subarray with equal 
// number of 0s and 1s. Also returns the size 
// of such subarray. 

int findSubArray(int arr[], int n) 
{ 
	// variables to store result values 

	int maxsize = -1, startindex; 

	// Create an auxiliary array sunmleft[]. 
	// sumleft[i] will be sum of array 
	// elements from arr[0] to arr[i] 

	int sumleft[n]; 

	// For min and max values in sumleft[] 

	int min, max; 
	int i; 

	// Fill sumleft array and get min and max 
	// values in it. Consider 0 values in arr[] 
	// as -1 

	sumleft[0] = ((arr[0] == 0)? -1: 1); 
	min = arr[0]; max = arr[0]; 
	for (i=1; i<n; i++) 
	{	 
		sumleft[i] = sumleft[i-1] + ((arr[i] == 0)? 
					-1: 1); 
		if (sumleft[i] < min) 
			min = sumleft[i]; 
		if (sumleft[i] > max) 
			max = sumleft[i]; 
	} 

	// Now calculate the max value of j - i such 
	// that sumleft[i] = sumleft[j]. The idea is 
	// to create a hash table to store indexes of all 
	// visited values. 
	// If you see a value again, that it is a case of 
	// sumleft[i] = sumleft[j]. Check if this j-i is 
	// more than maxsize. 
	// The optimum size of hash will be max-min+1 as 
	// these many different values of sumleft[i] are 
	// possible. Since we use optimum size, we need 
	// to shift all values in sumleft[] by min before 
	// using them as an index in hash[]. 

	int hash[max-min+1]; 

	// Initialize hash table 

	for (i=0; i<max-min+1; i++) 
		hash[i] = -1; 

	for (i=0; i<n; i++) 
	{ 
		// Case 1: when the subarray starts from 
		//		 index 0 

		if (sumleft[i] == 0) 
		{ 
		maxsize = i+1; 
		startindex = 0; 
		} 

		// Case 2: fill hash table value. If already 
		//		 filled, then use it 

		if (hash[sumleft[i]-min] == -1) 
			hash[sumleft[i]-min] = i; 
		else
		{ 
			if ((i - hash[sumleft[i]-min]) > maxsize) 
			{ 
				maxsize = i - hash[sumleft[i]-min]; 
				startindex = hash[sumleft[i]-min] + 1; 
			} 
		} 
	} 
	if (maxsize == -1) 
		printf("No such subarray"); 
	else
		printf("%d to %d", startindex, startindex+maxsize-1); 

	return maxsize; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {1, 0, 0, 1, 0, 1, 1}; 
	int size = sizeof(arr)/sizeof(arr[0]); 

	findSubArray(arr, size); 
	return 0; 
} 

