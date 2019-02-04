/*
   https://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/  
   like we do in merging the two sorted arrays. 
   take sum1 from array one.
   take sum2 from array two.
   if(both values are same) then add that to result directly.
*/
#include<iostream> 
using namespace std; 

// Utility function to find maximum of two integers 
int max(int x, int y) { return (x > y)? x : y; } 

// This function returns the sum of elements on maximum path 
// from beginning to end 
int maxPathSum(int ar1[], int ar2[], int m, int n) 
{ 
	// initialize indexes for ar1[] and ar2[] 
	int i = 0, j = 0; 

	// Initialize result and current sum through ar1[] and ar2[]. 
	int result = 0, sum1 = 0, sum2 = 0; 

	// Below 3 loops are similar to merge in merge sort 
	while (i < m && j < n) 
	{ 
		// Add elements of ar1[] to sum1 
		if (ar1[i] < ar2[j]) 
			sum1 += ar1[i++]; 

		// Add elements of ar2[] to sum2 
		else if (ar1[i] > ar2[j]) 
			sum2 += ar2[j++]; 

		else // we reached a common point 
		{ 
			// Take the maximum of two sums and add to result 
			result += max(sum1, sum2); 

			// Update sum1 and sum2 for elements after this 
			// intersection point 
			sum1 = 0, sum2 = 0; 

			// Keep updating result while there are more common 
			// elements 
			while (i < m && j < n && ar1[i] == ar2[j]) 
			{ 
				result = result + ar1[i++]; 
				j++; 
			} 
		} 
	} 

	// Add remaining elements of ar1[] 
	while (i < m) 
		sum1 += ar1[i++]; 

	// Add remaining elements of ar2[] 
	while (j < n) 
		sum2 += ar2[j++]; 

	// Add maximum of two sums of remaining elements 
	result += max(sum1, sum2); 

	return result; 
} 
void maxSumPath(int a[],int b[],int m,int n)
{
   int sum1=0;
   int sum2=0;
   int result =0;
   int i=0;
   int j=0;
   while(i < m && j < n)
   {
       if(a[i] < b[j])
         sum1+=a[i++];
       else if(a[i] > b[j])
         sum2+=b[j++];
       else
       {
         result+=max(sum1,sum2);
         sum1 =0;
         sum2 =0;
         while(i<m && j<n && a[i]==b[j])
         {
           result+=a[i++]; j++;
         }
       }
   }
   while(i<m)
     sum1+=a[i];
   while(j<n);
     sum2+=b[j];
   result +=max(sum1,sum2);
   cout<<result;
}
// Driver program to test above function 
int main() 
{ 
	int ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}; 
	int ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}; 
	int m = sizeof(ar1)/sizeof(ar1[0]); 
	int n = sizeof(ar2)/sizeof(ar2[0]); 
	cout << "Maximum sum path is "
		<< maxPathSum(ar1, ar2, m, n); 
	return 0; 
} 

