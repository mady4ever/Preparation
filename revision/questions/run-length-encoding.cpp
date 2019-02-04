/*
   https://www.geeksforgeeks.org/run-length-encoding/
*/
#include<bits/stdc++.h>
using namespace std;
int getFrequency(string input, int i)
{
  int c=0;
  for(int j=i+1;j<input.length();j++)
  {
     if(input[j] == input[j-1])
       c++;
     else
       return c+1;
  }
  return c+1;
}
string RLE(string input)
{
  string output;
  int i=0;
  while(i<input.length())
  {
    int c = getFrequency(input,i);
    output += input[i];
    output += to_string(char(c));
    //cout<<output<<endl;
    if(c==0)
      i++;
    else
     i+=c;
    //if(i>input.length())
     //break;
  }
  //cout<<output<<endl;
  return input.length() > output.length() ? output:input ;
} 
int main()
{
  cout<<RLE("mahendra");
  return 0;
}
