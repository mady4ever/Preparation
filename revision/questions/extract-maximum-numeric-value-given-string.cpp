/*
  https://www.geeksforgeeks.org/extract-maximum-numeric-value-given-string/
  val = val*10+isdigit(a[index])
*/
#include<bits/stdc++.h>
using namespace std;
bool isDig(string input,int d)
{
  if(input[d] >= '0' && input[d] <= '9')
    return true;
  return false;
}
int maxValue(string input)
{
  int max_value=0;
  int cur=0;
  for(int i=0;i<input.length();i++)
  {    
    if(isDig(input,i))
    {
     cur = cur*10 + (input[i] - '0');
     max_value = max(cur,max_value);
    }
    else
      cur=0;
  }
  return max_value;
}
int main()
{
  string input = "100klh564abc365bg";
  cout<<maxValue(input);
  return 0;
}
