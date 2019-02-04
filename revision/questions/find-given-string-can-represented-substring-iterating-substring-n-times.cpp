/*
  https://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/
*/
// A C++ program to check if a string is 'n' times 
// repetition of one of its substrings 
#include<iostream> 
#include<cstring> 
using namespace std; 

// A utility function to fill lps[] or compute prefix funcrion 
// used in KMP string matching algorithm. Refer 
// https://www.geeksforgeeks.org/archives/11902 for details 
void computeLPSArray(char str[], int M, int lps[]) 
{ 
	int len = 0; //lenght of the previous longest prefix suffix 
	int i; 

	lps[0] = 0; //lps[0] is always 0 
	i = 1; 

	// the loop calculates lps[i] for i = 1 to M-1 
	while (i < M) 
	{ 
	if (str[i] == str[len]) 
	{ 
		len++; 
		lps[i] = len; 
		i++; 
	} 
	else // (pat[i] != pat[len]) 
	{ 
		if (len != 0) 
		{ 
			// This is tricky. Consider the example AAACAAAA 
			// and i = 7. 
			len = lps[len-1]; 

			// Also, note that we do not increment i here 
		} 
		else // if (len == 0) 
		{ 
			lps[i] = 0; 
			i++; 
		} 
	} 
	} 
} 

// Returns true if str is repetition of one of its substrings 
// else return false. 
bool isRepeat(char str[]) 
{ 
	// Find length of string and create an array to 
	// store lps values used in KMP 
	int n = strlen(str); 
	int lps[n]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(str, n, lps); 

	// Find length of longest suffix which is also 
	// prefix of str. 
	int len = lps[n-1]; 

	// If there exist a suffix which is also prefix AND 
	// Length of the remaining substring divides total 
	// length, then str[0..n-len-1] is the substring that 
	// repeats n/(n-len) times (Readers can print substring 
	// and value of n/(n-len) for more clarity. 
	return (len > 0 && n%(n-len) == 0)? true: false; 
} 

// Driver program to test above function 
int main() 
{ 
char txt[][100] = {"ABCABC", "ABABAB", "ABCDABCD", "GEEKSFORGEEKS", 
					"GEEKGEEK", "AAAACAAAAC", "ABCDABC"}; 
int n = sizeof(txt)/sizeof(txt[0]); 
for (int i=0; i<n; i++) 
	isRepeat(txt[i])? cout << "True\n" : cout << "False\n"; 
return 0; 
} 

