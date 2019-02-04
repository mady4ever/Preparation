/*
  https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
*/
#include<bits/stdc++.h>
using namespace std;
int getSum(int a[],int s)
{
  int sum=0;
  for(int i=0;i<s;i++)
    sum+=a[i];
  return sum;
}
bool equilibriumIndex(int a[],int s)
{
    int sum = getSum(a,s);
    //int index =0;
    int c_sum=0;
    //while(index < s)
    //{
    //   c_sum+=a[index];
    //   if(c_sum == (sum-c_sum))
    //      return true;
    //   else if (c_sum > (sum-c_sum))
    //      return false;
    //   index++;
    //}
    for(int i=0;i<s;i++)
    {
      c_sum +=a[i];
      if(c_sum == (sum-c_sum))
        return true;
    }
    return false;
}
int main()
{
   int arr[] = { -7, 1, 5, 2, -4, 3, 0 }; 
   int arr_size = sizeof(arr) / sizeof(arr[0]);
   cout<<equilibriumIndex(arr,arr_size);
   return 0;
}
