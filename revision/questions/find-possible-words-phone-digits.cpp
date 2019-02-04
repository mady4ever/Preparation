/*
  https://www.geeksforgeeks.org/find-possible-words-phone-digits/
*/
#include<bits/stdc++.h>
using namespace std;
vector<string> words[10];// = {"","","abc", "def", "ghi", "jkl", 
                       //        "mno", "pqrs", "tuv", "wxyz"};
void printWords(void);
void possible(string input,int i,string output)
{
   if(input[i] == '0' || input[i]=='1')
          return;
   if(i == input.length())
   {
     cout<<output<<endl;
     return;
   }
   for(auto j: words[input[i]-'0'])
   { 
      for(auto k : j)
      {
        output[i]=k; // replace the previous char here.
        possible(input,i+1,output);
      }
   }
}
void printWords(void)
{
  for(int i=0;i<10;i++)
  {
    cout<<i<<" : \t";
    for(auto j:words[i])
      cout<<j<<"\t";
    cout<<endl;
  }
}
int main()
{
  words[0].push_back("");
  words[1].push_back("");
  words[2].push_back("abc");
  words[3].push_back("def");
  words[4].push_back("ghi");
  words[5].push_back("jkl");
  words[6].push_back("mno");
  words[7].push_back("pqrs");
  words[8].push_back("tuv");
  words[9].push_back("wxyz");  
  printWords();
  possible("234",0,"   ");
  return 0;
}
