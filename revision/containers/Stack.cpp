#include<iostream>
#include<stack>
using namespace std;
int main()
{
  stack<int> st;
  for(int i=0;i<10;i++)
   st.push(i*i);
  while(!st.empty())
  {
     cout<<st.top()<<"\t";
     st.pop();
  }
  return 0;
}
