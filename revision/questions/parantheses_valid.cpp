/*
Parens: Implement an algorithm to print all valid (i.e., properly opened and closed) combinations of n pairs of parentheses. 
EXAMPLE Input: 3 
Output: (( () ) ) , ( () () ) , ( () ) () , () ( () ) , ()( ) () 
*/
#include<bits/stdc++.h>
using namespace std;
string addAfter(string input,int i)
{
   string left = input.substr(0,i-1);
   string right = input.substr(i+1,input.length());
   return left + "()" + right;
}
set<string> allParentheses(int num)
{
   set<string> set;// = new set<string>();
   if(num == 0)
   {
     set.insert("");
   }
   else
   {
     auto prev = allParentheses(num-1); // get the previous set output
     for(auto pr : prev) // iterate thorugh previous set and get the index of open parenthesis.
     {
       for(int i=0;i<pr.length();i++)
       {
         if(pr[i]=='(')
         {
           set.insert(addAfter(pr,i));
         }
       }
       set.insert("()"+pr);
     }      
   }
   return set;
}
int main()
{
  set<string> s = allParentheses(3);
  for(auto i:s)
    cout<<i<<"\n";
  return 0;
}
