/*
  https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
  idea is simple to consider every element. included and excluded fashion.
  in case of sum is going down then treat it's not valid solution.
  in case of current coints is greater than sum then igoner that coint and move to next.
*/
#include<bits/stdc++.h>
using namespace std;
int minCouns(int c[],int i,int sum,int s)
{
  cout<<i<<"\t"<<sum<<endl;
  if(sum < 0)
    return INT_MAX;
  if(i>s-1)
    return 0;
  if(sum==0 && i==s-1)
    return 0;
  if(c[i] > sum)
    return minCouns(c,i+1,sum,s);
  return min(minCouns(c,i+1,sum-c[i],s),minCouns(c,i+1,sum,s)) + 1;
}
int main()
{
  int c[]={25, 15, 5 , 3};
  int Sum = 20;
  //int c[]={9, 6, 5, 1};
  //int Sum=13;
  int s = sizeof(c)/sizeof(c[0]);
  cout<<minCouns(c,0,Sum,s);
  return 0;
}
/*
// A Dynamic Programming based C++ program to find minimum of coins 
// to make a given change V 
#include<bits/stdc++.h> 
using namespace std; 

// m is size of coins array (number of different coins) 
int minCoins(int coins[], int m, int V) 
{ 
	// table[i] will be storing the minimum number of coins 
	// required for i value. So table[V] will have result 
	int table[V+1]; 

	// Base case (If given value V is 0) 
	table[0] = 0; 

	// Initialize all table values as Infinite 
	for (int i=1; i<=V; i++) 
		table[i] = INT_MAX; 

	// Compute minimum coins required for all 
	// values from 1 to V 
	for (int i=1; i<=V; i++) 
	{ 
		// Go through all coins smaller than i 
		for (int j=0; j<m; j++) 
		if (coins[j] <= i) 
		{ 
			int sub_res = table[i-coins[j]]; 
			if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
				table[i] = sub_res + 1; 
		} 
	} 
	return table[V]; 
} 

// Driver program to test above function 
int main() 
{ 
	int coins[] = {9, 6, 5, 1}; 
	int m = sizeof(coins)/sizeof(coins[0]); 
	int V = 11; 
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V); 
	return 0; 
} 

*/
