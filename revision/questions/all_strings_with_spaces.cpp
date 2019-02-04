/*
  https://www.geeksforgeeks.org/print-possible-strings-can-made-placing-spaces/
*/
#include<bits/stdc++.h>
using namespace std;
void printAllStrings(string input, int index, string output, int s)
{
   if(index == s)
   {
     cout<<output<<endl;
     return;
   }
   output += input[index]; 
   //cout<<" temp output :"<<output<<endl;
   printAllStrings(input,index + 1, output,s);
   output += " "; 
   output += input[index];
   //cout<<" temp output :"<<output<<endl;
   printAllStrings(input, index + 1, output,s);
}
void allStrings(char input[], char buf[], int i, int j, int s)
{
   if(i == s)
   {
     buf[j] = '\0';
     cout<<buf<<endl;
     return;
   }
   buf[j] = input[i];
   allStrings(input, buf, i + 1, j + 1, s);
   buf[j] = ' ';
   buf[j+1] = input[i];
   allStrings(input,buf,i+1,j+2,s);
}
void testString(void)
{
  string input("ABC");
  //max A_B_C <-- 2 * length("ABC") - 1;
  //int index = 0;
  printAllStrings(input,1,"A", input.length());
  cout<<"\n **************************\n";
}
int main()
{
  //string input("ABC");
  // max A_B_C <-- 2 * length("ABC") - 1;
  //char buf[2*input.length()];
  //printAllStrings(input,1,"A");
  testString(); 
  char input[] = "ABC";
  int s = strlen(input);
  char buf[2*s];
  buf[0] = input[0];
  allStrings(input, buf,1,1,s);
  return 0;
}
