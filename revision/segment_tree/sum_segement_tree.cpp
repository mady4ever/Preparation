/*
   https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
*/
#include<bits/stdc++.h>
using namespace std;
int getmid(int s, int e)
{
  return (s + e)/2;
}
int constructSTUtil(int a[], int *sgt, int ss, int se, int index)
{
   if(ss == se)
   {
     sgt[index] = a[ss];
     return a[ss];
   }
   int mid = getmid(ss,se);
   sgt[index] =  constructSTUtil(a,sgt,ss,mid,2*index+1) + 
          constructSTUtil(a,sgt,mid+1,se,2*index+2);
   return sgt[index];
}
int *constructST(int a[], int size)
{
   int *sgt = new int[2*size-1];
   constructSTUtil(a,sgt,0,size-1,0);
   return sgt;
}
int getSumRangeUtil(int *sgt, int ss, int se, int qs, int qe, int index)
{
  if(qs <= ss && se <= qe)
    return sgt[index];
  if(se < qs || ss > qe)
      return 0;
  int mid = getmid(ss,se); //get mid index.
  return getSumRangeUtil(sgt,ss,mid,qs,qe,2*index+1) + 
         getSumRangeUtil(sgt,mid+1,se,qs,qe,2*index+2); 
}
int getSumRange(int *sgt, int l, int r, int size)
{
   if(l > r || l > size || r > size || l < 0)
      return -1; // raise exception.
   return getSumRangeUtil(sgt,0,size-1,l,r,0);
}
void updateUtil(int i, int *sgt, int ss, int se, int diff, int index)
{
  if(i < ss || i > se)
      return;
  sgt[index] = sgt[index] + diff;
  if(ss != se) // non leaf nodes updates.
  {
    int mid = getmid(ss,se);
    updateUtil(i,sgt,ss,mid,diff,2*index+1);
    updateUtil(i,sgt,mid+1,se,diff,2*index+2);
  }
}
void update(int a[],int *sgt, int i, int v, int size)
{
   if(i<0 || i > size)
      return;
   int diff = v - a[i];
   a[i] = v;
   updateUtil(i,sgt,0,size-1,diff,0);
}
int main()
{
  int a[]={1,2,3,4,5,6,7,8,9,10};
  int s = sizeof(a)/sizeof(a[0]);
  int *sgt = constructST(a,s);  
  cout<<getSumRange(sgt,0,5,s);
  update(a,sgt,0,10,s);
  cout<<endl<<getSumRange(sgt,0,5,s); 
  return 0;
}
