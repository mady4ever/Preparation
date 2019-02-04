/*
   find point in array such that a[i]=i
   do binary search.
*/
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high) 
{ 
    if(high >= low) 
    { 
        int mid = (low + high)/2;  /*low + (high - low)/2;*/
        if(mid == arr[mid]) 
            return mid; 
        if(mid > arr[mid]) 
            return binarySearch(arr, (mid + 1), high); 
        else
            return binarySearch(arr, low, (mid -1)); 
    } 
  
    /* Return -1 if there is no Fixed Point */
    return -1; 
} 
  
/* Driver program to check above functions */
int main() 
{ 
    int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Fixed Point is %d", binarySearch(arr, 0, n-1)); 
    getchar(); 
    return 0; 
} 
