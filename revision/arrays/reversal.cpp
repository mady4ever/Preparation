#include<iostream>
#include<algorithm>
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
void reverse(int a[], int s)
{
   int l=0,r = s-1;
   while(l<=r)
   {
     swap(a[l],a[r]);
     l++;
     r--;
   }
}
int main()
{
  int a[]={1,2,3,4,5};
  int s = sizeof(a)/sizeof(int);
  rotaten(a,s,3); 
  print(a,s);
  reverse(a,s);
  print(a,s);
  return 0;
}
