/*
  https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
  using the swaping logic to to the permutations.
                  abc
          abc     bac      bca
      bac  cba  abc cab  cba acb
*/
#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
   a = a^b;
   b = a^b;
   a = a^b;
}
void permutations(string input, int l,int r)
{
   if(l==r)
   {
     cout<<input<<"\t";
     //return;
   }
   else 
   {
    for(int i=l;i<=r;i++)
    {
      swap(input[l],input[i]); // swap the values and do pemutations.
      permutations(input,l+1,r);
      swap(input[l],input[i]); // backtrack the values again.
    }
   }
}
int main()
{
   string input = "ABC";
   permutations(input,0,input.length()-1);
   return 0; 
}
