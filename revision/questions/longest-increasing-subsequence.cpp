/*
  https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
  create one more array of same size and mark all as 1
  now for ever element check in previsous if any one has max langth including current length.
  finally return the max length from newly created array. 
  Complexity is: O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSequence(int a[],int s)
{
  int buf[s];
  for(int i=0;i<s;i++)
     buf[i]=1;
  for(int i=1;i<s;i++)
  {
    for(int j=i-1; j>=0;j--)
    {
       if(a[j] < a[i]  && buf[i] < buf[j]+1)
       {
         buf[i] = max(buf[i],buf[j]+1);
       }
    }
  }
  return *max_element(buf,buf+s);
}
int main()
{ 
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<longestIncreasingSequence(arr,n);
  return 0;
}
