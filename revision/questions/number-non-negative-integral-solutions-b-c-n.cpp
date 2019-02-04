/*
 (n+1)*(n+2)/2
 https://www.geeksforgeeks.org/number-non-negative-integral-solutions-b-c-n/
*/
// A naive C++ solution to count solutions of 
// a + b + c = n 
#include<bits/stdc++.h> 
using namespace std; 

// Returns count of solutions of a + b + c = n 
int countIntegralSolutions(int n) 
{ 
	return ((n+1)*(n+2))/2; 
} 

// Driver code 
int main() 
{ 
	int n = 3; 
	cout << countIntegralSolutions(n); 
	return 0; 
}

