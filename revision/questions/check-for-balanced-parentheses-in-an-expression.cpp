/*
  https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
*/
#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string input)
{
  stack<char> st;
  for(int i=0;i<input.length();i++)
  {
    cout<<"start :"<<input[i]<<endl;
    if(input[i] == '(' || input[i] == '{' || input[i] == '[')
      st.push(input[i]);
    else if(input[i] == ')' || input[i] == '}' || input[i] == ']')
    {
       if(st.empty())
         return false;
       else
       {
          cout<<"remove :"<<st.top()<<endl;
          st.pop();
       }
    }
  }
  //cout<<st.empty();
  return st.empty();
}
int main()
{
  string input="([])[]()";
  cout<<isBalanced(input);
  return 0;
}
