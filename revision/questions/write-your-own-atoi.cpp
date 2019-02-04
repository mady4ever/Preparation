/*
  https://www.geeksforgeeks.org/write-your-own-atoi/
  number = number*10 + input[index];
*/
#include<bits/stdc++.h>
using namespace std;
int stringToInt(string input)
{
   int num=0;
   for(int i=0;i<input.length();i++)
   {
     num = num*10 + (input[i]-'0');
   }
   return num;
}
int main()
{
  string input="1234";
  cout<<stringToInt(input);
  return 0;
}
