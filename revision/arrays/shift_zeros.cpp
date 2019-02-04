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
void shiftzeros(int a[], int s)
{
  int l=0,r = s-1;
  while(l<=r)
  {
    if(a[l]>0)
    {
     //swap(a[l],a[r]);
     l++;
     //r--;    
    }
    if(a[r]==0)
    {
      r--;
    }
    if(a[l]==0 && a[r]>0)
      swap(a[l],a[r]);
    l++; 
    r--;
  }
}
void shiftzeros1(int a[], int s)
{
   int c=0;
   for(int i=0;i<s;i++)
     if(a[i]!=0)
     a[c++] = a[i];
   while(c<s)
   { 
     a[c] = 0;
     c++;
   }
}
int main()
{
  int a[]={0,10,1,0,0};
  int s = sizeof(a)/sizeof(int);
  //rotaten(a,s,3); 
  print(a,s);
  shiftzeros1(a,s);
  print(a,s);
  return 0;
}
