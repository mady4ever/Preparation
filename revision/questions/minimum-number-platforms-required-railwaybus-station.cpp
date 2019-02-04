/*
  https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
  sort the timings with nlogn
  now iterate through the sequence and if start encounter then increment the counter if stop encounter then decrement the counter.
  keep them max counter which is nothing but max number of flatforms required.
*/
// Program to find minimum number of platforms 
// required on a railway station 
#include<iostream> 
#include<algorithm> 

using namespace std; 

// Returns minimum number of platforms reqquired 
int findPlatform(int arr[], int dep[], int n) 
{ 
// Sort arrival and departure arrays 
sort(arr, arr+n); 
sort(dep, dep+n); 

// plat_needed indicates number of platforms 
// needed at a time 
int plat_needed = 1, result = 1; 
int i = 1, j = 0; 

// Similar to merge in merge sort to process 
// all events in sorted order 
while (i < n && j < n) 
{ 
	// If next event in sorted order is arrival, 
	// increment count of platforms needed 
	if (arr[i] <= dep[j]) 
	{ 
		plat_needed++; 
		i++; 

		// Update result if needed 
		if (plat_needed > result) 
			result = plat_needed; 
	} 

	// Else decrement count of platforms needed 
	else
	{ 
		plat_needed--; 
		j++; 
	} 
} 

return result; 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(arr, dep, n); 
	return 0; 
} 

