/*
  https://www.geeksforgeeks.org/find-equal-point-string-brackets/
  maintain two arrays one for open brackets from left side.
  other arry for closed brackets from end.
  check equallity of the open and closed in both arrays and print.
*/
// C++ program to find an index k which 
// decides the number of opening brackets 
// is equal to the number of closing brackets 
#include<bits/stdc++.h> 
using namespace std; 

// Function to find an equal index 
int findIndex(string str) 
{ 
	int len = str.length(); 
	int open[len+1], close[len+1]; 
	int index = -1; 
	memset(open, 0, sizeof (open)); 
	memset(close, 0, sizeof (close)); 

	open[0] = 0; 
	close[len] = 0; 
	if (str[0]=='(') 
		open[1] = 1; 
	if (str[len-1] == ')') 
		close[len-1] = 1; 

	// Store the number of opening brackets 
	// at each index 
	for (int i = 1; i < len; i++) 
	{ 
		if ( str[i] == '(' ) 
			open[i+1] = open[i] + 1; 
		else
			open[i+1] = open[i]; 
	} 

	// Store the number of closing brackets 
	// at each index 
	for (int i = len-2; i >= 0; i--) 
	{ 
		if ( str[i] == ')' ) 
			close[i] = close[i+1] + 1; 
		else
			close[i] = close[i+1]; 
	} 

	// check if there is no opening or closing 
	// brackets 
	if (open[len] == 0) 
		return len; 
	if (close[0] == 0) 
		return 0; 

	// check if there is any index at which 
	// both brackets are equal 
	for (int i=0; i<=len; i++) 
		if (open[i] == close[i]) 
			index = i; 

	return index; 
} 

// Driver code 
int main() 
{ 
	string str = "(()))(()()())))"; 
	cout << findIndex(str); 
	return 0; 
} 
