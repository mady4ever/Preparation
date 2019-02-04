/*
 https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/
*/

// C++ program to print minimum number that can be formed 
// from a given sequence of Is and Ds 
#include <bits/stdc++.h> 
using namespace std; 

// Function to decode the given sequence to construct 
// minimum number without repeated digits 
void PrintMinNumberForPattern(string seq) 
{ 
	// result store output string 
	string result; 

	// create an empty stack of integers 
	stack<int> stk; 

	// run n+1 times where n is length of input sequence 
	for (int i = 0; i <= seq.length(); i++) 
	{ 
		// push number i+1 into the stack 
		stk.push(i + 1); 

		// if all characters of the input sequence are 
		// processed or current character is 'I' 
		// (increasing) 
		if (i == seq.length() || seq[i] == 'I') 
		{ 
			// run till stack is empty 
			while (!stk.empty()) 
			{ 
				// remove top element from the stack and 
				// add it to solution 
				result += to_string(stk.top()); 
				result += " "; 
				stk.pop(); 
			} 
		} 
	} 

	cout << result << endl; 
} 

// main function 
int main() 
{ 
	PrintMinNumberForPattern("IDID"); 
	PrintMinNumberForPattern("I"); 
	PrintMinNumberForPattern("DD"); 
	PrintMinNumberForPattern("II"); 
	PrintMinNumberForPattern("DIDI"); 
	PrintMinNumberForPattern("IIDDD"); 
	PrintMinNumberForPattern("DDIDDIID"); 
	return 0; 
} 

