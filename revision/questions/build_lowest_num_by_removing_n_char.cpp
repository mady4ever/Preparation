/*
  https://www.geeksforgeeks.org/build-lowest-number-by-removing-n-digits-from-a-given-number/
*/
#include<bits/stdc++.h>
using namespace std;
void buildNumber(string input, int n, string &output)
{
  if(n == 0)
  {
    output += input;
    return;
  }
  if(input.length() < n)
     return;
  int min_index =0;
  int min_v = input[0];
  for(int i=1;i<n;i++)
     if(min_v > input[i])
       min_index = i;
  output += input[min_index];
  return buildNumber(input.substr(min_index+1,input.length()-1), n - min_index,output);
}
int main()
{
  string str = "121198"; 
  int n = 2; 
  string output;
  buildNumber(str,n,output);
  cout<<"\n"<<output;
  return 0;
}
