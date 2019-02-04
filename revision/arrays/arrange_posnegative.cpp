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
void arragenposneg(int a[], int s)
{
   int l=0, r =s-1;
   while(l<=r)
   {
     if(a[l]<=0)
        l++;
     else if(a[r]> 0)
        r--;
     else
     {
       swap(a[l],a[r]);
       l++; r--;
     }
   }
   print(a,s);
   l=1;r = s-1;
   while(l <= r)
   {
     if(a[l] <= 0 && a[r] > 0)
     {
       swap(a[l],a[r]);
       l+=2;
       r--;
       continue;   
     }     
     if(a[r] < 0 && a[l]>0)
     {
       swap(a[l],a[r]);
       l+=2; r--;
       continue;
     }
     l+=2;         
     r--;
   }
   print(a,s);
}
int main()
{
  int a[]={1,2,3,-4,-5,6};
  int s = sizeof(a)/sizeof(int);
  //rotaten(a,s,3); 
  //print(a,s);
  arragenposneg(a,s);
  return 0;
}
