/*
  https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
*/
#include<bits/stdc++.h>
using namespace std;
int min(int a, int b)
{
   return a<b?a:b;
}
int getmid(int s, int e)
{
   return (s + e)/2;
}
int constructRMQUtil(int a[], int *sgt,int ss, int se, int i)
{
   if(ss==se)
   {
     sgt[i] = a[ss];
     return a[ss];
   }
   int mid = getmid(ss,se);
   sgt[i] = min(constructRMQUtil(a,sgt,ss,mid,2*i+1),
                constructRMQUtil(a,sgt,mid+1,se,2*i+2));
   return sgt[i];   
}
int* constructRMQ(int a[], int size)
{
  int *sgt = new int[2*size-1];
  constructRMQUtil(a,sgt,0,size-1,0);
  return sgt; 
}
int getRMQUtil(int *sgt, int ss, int se, int qs, int qe, int i)
{
   if(qs <= ss && se <= qe)
     return sgt[i];
   if(qe < ss || se < qs)
     return INT_MAX;
   int mid = getmid(ss,se);
   return min(getRMQUtil(sgt,ss,mid,qs,qe,2*i+1), getRMQUtil(sgt,mid+1,se,qs,qe,2*i+2));
}
int getRMQ(int *sgt, int qs, int qe, int size)
{
   if(qs > qe || qs < 0 || qs > size || qe > size)
      return -1;
   return getRMQUtil(sgt,0,size-1,qs,qe,0);  
}
int main()
{
  int a[] = {10,2,3,4,5,6,7,8,9};
  int s = sizeof(a)/sizeof(a[0]);
  int *sgt = constructRMQ(a,s);
  cout<<getRMQ(sgt,0,5,s);
  return 0;
}
