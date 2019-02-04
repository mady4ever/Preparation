/*
  https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
  problem can be solved very easily by using DP.
  "123"
  start from second index and if first index value is less than or equal to 2 then mark it as 1.
  a[0] = 1;
  for second index check it's previous index has less than equal to 6 (26 charecters) then add a[i-1] + 1 = a[i] else a[i] = a[i-1];
*/
// A Dynamic Programming based C++ implementation to count decodings 
#include <iostream> 
#include <cstring> 
using namespace std; 

// A Dynamic Programming based function to count decodings 
int countDecodingDP(char *digits, int n) 
{ 
	int count[n+1]; // A table to store results of subproblems 
	count[0] = 1; 
	count[1] = 1; 

	for (int i = 2; i <= n; i++) 
	{ 
		count[i] = 0; 

		// If the last digit is not 0, then last digit must add to 
		// the number of words 
		if (digits[i-1] > '0') 
			count[i] = count[i-1]; 

		// If second last digit is smaller than 2 and last digit is 
		// smaller than 7, then last two digits form a valid character 
		if (digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7') ) 
			count[i] += count[i-2]; 
	} 
	return count[n]; 
} 

// Driver program to test above function 
int main() 
{ 
	char digits[] = "1234"; 
	int n = strlen(digits); 
	cout << "Count is " << countDecodingDP(digits, n); 
	return 0; 
} 

