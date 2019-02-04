/*
  recursively remove the left and right and check the 2*min ? max.
  https://www.geeksforgeeks.org/remove-minimum-elements-either-side-2min-max/
  we can solve it by DP by storing the intermidiant results into hash map.
  key is equal to i.append(j) value equal to minimum values.
*/
#include<bits/stdc++.h>
using namespace std;
int mintobecomemax(int a[],int l,int r)
{
  if(l>=r) return 0;
  //if(r<l) return 0;
  int mi = *min_element(a+l,a+r);
  int mx = *max_element(a+l,a+r);
  if(2*mi > mx)
    return 0;
  return min(mintobecomemax(a,l+1,r),mintobecomemax(a,l,r-1))+1;
}
int main()
{
  int arr[] = {4, 5, 100, 9, 10, 11, 12, 15, 200}; 
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<mintobecomemax(arr,0,n);
  return 0;
}
