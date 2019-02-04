/*
  https://www.geeksforgeeks.org/find-top-k-or-most-frequent-numbers-in-a-stream/
*/
// C++ program to find top k elements in a stream 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print top k numbers 
void kTop(int a[], int n, int k) 
{ 
	// vector of size k+1 to store elements 
	vector<int> top(k + 1); 

	// array to keep track of frequency 
	unordered_map<int, int> freq; 

	// iterate till the end of stream 
	for (int m = 0; m < n; m++) 
	{ 
		// increase the frequency 
		freq[a[m]]++; 

		// store that element in top vector 
		top[k] = a[m]; 

		// search in top vector for same element 
		auto it = find(top.begin(), top.end() - 1, a[m]); 

		// iterate from the position of element to zero 
		for (int i = distance(top.begin(), it) - 1; i >= 0; --i) 
		{ 
			// compare the frequency and swap if higher 
			// frequency element is stored next to it 
			if (freq[top[i]] < freq[top[i + 1]]) 
				swap(top[i], top[i + 1]); 

			// if frequency is same compare the elements 
			// and swap if next element is high 
			else if ((freq[top[i]] == freq[top[i + 1]]) 
					&& (top[i] > top[i + 1])) 
				swap(top[i], top[i + 1]); 
			else
				break; 
		} 

		// print top k elements 
		for (int i = 0; i < k && top[i] != 0; ++i) 
			cout << top[i] << ' '; 
	} 
	cout << endl; 
} 

// Driver program to test above function 
int main() 
{ 
	int k = 4; 
	int arr[] = { 5, 2, 1, 3, 2 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	kTop(arr, n, k); 
	return 0; 
} 
