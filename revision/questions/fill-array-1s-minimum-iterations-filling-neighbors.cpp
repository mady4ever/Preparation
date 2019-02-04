/*
  https://www.geeksforgeeks.org/fill-array-1s-minimum-iterations-filling-neighbors/
  case 1: starts with 000001 or ends with 100000
  case 2: have *11100000111* combination.
  case 3: 000000 combination or invalid combination.
*/
#include<bits/stdc++.h>
using namespace std;
int countIterations(int arr[], int n) 
{ 
    bool oneFound = false; 
    int res = 0; 
    // Start traversing the array 
    for (int i=0; i<n; ) 
    { 
        if (arr[i] == 1) 
          oneFound = true; 
  
        // Traverse until a 0 is found 
        while (i<n && arr[i]==1) 
            i++; 
  
        // Count contiguous 0s 
        int count_zero = 0; 
        while (i<n && arr[i]==0) 
        { 
            count_zero++; 
            i++; 
        } 
  
        // Condition for Case 3 
        if (oneFound == false && i == n) 
            return -1; 
  
        // Condition to check if Case 1 satisfies: 
        int curr_count; 
        if (i < n && oneFound == true) 
        { 
            // If count_zero is even 
            if (count_zero & 1 == 0) 
                curr_count = count_zero/2; 
  
            // If count_zero is odd 
            else
                curr_count = (count_zero+1)/2; 
  
            // Reset count_zero 
            count_zero = 0; 
        } 
  
        // Case 2 
        else
        { 
            curr_count = count_zero; 
            count_zero = 0; 
        } 
  
        // Update res 
        res = max(res, curr_count); 
    } 
  
    return res; 
}
int main()
{
  int arr[] = {0, 1, 0, 0, 1, 0, 0, 
                 0, 0, 0, 0, 0, 1, 0}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  cout << countIterations(arr, n); 
  return 0;
}
