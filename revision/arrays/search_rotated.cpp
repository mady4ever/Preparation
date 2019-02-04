#include<iostream>
using namespace std;
void rotate(int a[], int s)
{
   if(s==0)
     return;
   int t = a[0];
   for(int i=0;i<s-1;i++)
     a[i] = a[i+1];
   a[s-1] = t;
   //for(int i=0;i<s;i++)
   // cout<<a[i]<<"\t";
}
void rotaten(int a[], int s, int r)
{
   r = r % s;
   for(int i=r;i < s; i++)
    rotate(a,s);
}
void print(int a[], int s)
{
   for(int i=0;i<s;i++)
    cout<<a[i]<<"\t";
   cout<<endl;
}
bool search(int a[],int s, int l, int r, int i)
{
   cout<<l<<" "<<r<<endl;
   if( l < 0 || l > r || r > s || l > s)
     return false;
   int m = (l+r)/2;
   if(i == a[m])
     return true;
   if(a[l] <= a[m] && a[l] <= i && i <= a[m])
   {
       return search(a,s,l,m-1,i);
   }
   else
      return search(a,s,m+1,r,i);
   //return false;
}
int main()
{
  int a[]={1,2,3,4,5};
  int s = sizeof(a)/sizeof(int);
  rotaten(a,s,3); 
  print(a,s);
  cout<<search(a,s,0,s-1,0);
  return 0;
}
