/*
  https://www.geeksforgeeks.org/combinational-sum/
  It's a backtracking problem.
  if current element causes to become sum == 0 then print the result else remove from result and go ahead.
*/
#include<bits/stdc++.h>
using namespace std;
/*
bool combination_sum(int a[], int s, int x,int i,vector<int> res)
{
   if(x==0)
   {
     cout<<a[i];
     return true;
   }
   if(i>=s) return false;
   if(a[i] > x)
     return combination_sum(a,s,x,i+1);
   else
   {
      if(combination_sum(a,s,x-a[i],i+1) || combination_sum(a,s,x-a[i],i))
        return true;
   }
   return false;
}*/
void c_sum(int a[],int s,int x,int i,vector<int> res)
{
   if(x==0)
   {
     for(auto i:res)
      cout<<i<<"\t";
     cout<<endl;
     return;
   }
   if(i>s)
    return;
   while(i < s && (x-a[i])>=0)
   {
     res.push_back(a[i]);
     c_sum(a,s,x-a[i],i,res);
     i++;
     res.pop_back(); 
   }
}
int main()
{

  int a[]={2, 4, 6, 8};
  int s = sizeof(a)/sizeof(a[0]);
  int num = 8;
  //combination_sum(a,s,num,0);
  vector<int> res;
  c_sum(a,s,num,0,res);
  return 0;
}
