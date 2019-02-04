/*
 https://www.geeksforgeeks.org/longest-consecutive-subsequence/
 use hashmap to insert all the elements into it.
 check for every element next consucutive element is present and track the length of it.
 update the max length of it.
*/
// C++ program to find longest contiguous subsequence 
#include<bits/stdc++.h> 
using namespace std; 

// Returns length of the longest contiguous subsequence 
int findLongestConseqSubseq(int arr[], int n) 
{ 
	unordered_set<int> S; 
	int ans = 0; 

	// Hash all the array elements 
	for (int i = 0; i < n; i++) 
		S.insert(arr[i]); 

	// check each possible sequence from the start 
	// then update optimal length 
	for (int i=0; i<n; i++) 
	{ 
		// if current element is the starting 
		// element of a sequence 
		if (S.find(arr[i]-1) == S.end()) 
		{ 
			// Then check for next elements in the 
			// sequence 
			int j = arr[i]; 
			while (S.find(j) != S.end()) 
				j++; 

			// update optimal length if this length 
			// is more 
			ans = max(ans, j - arr[i]); 
		} 
	} 
	return ans; 
} 

// Driver program 
int main() 
{ 
	int arr[] = {1, 9, 3, 10, 4, 20, 2}; 
	int n = sizeof arr/ sizeof arr[0]; 
	cout << "Length of the Longest contiguous subsequence is "
		<< findLongestConseqSubseq(arr, n); 
	return 0; 
} 

