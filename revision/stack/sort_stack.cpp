#include<iostream>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &st, int i)
{
   if(st.empty() || st.top() < i)
   {
     st.push(i);
     return;
   }
   int k = st.top();
   st.pop();
   insert(st,i);
   st.push(k);
}
void sort(stack<int> &st)
{
   if(!st.empty())
   {
    int t = st.top();
    st.pop();
    cout<<t<<endl;
    sort(st);
    insert(st, t);
   }
}
int main()
{
  stack<int> s;
  s.push(200);
  s.push(-1);
  s.push(100);
  sort(s);
  while(!s.empty())
  {
    cout<<s.top()<<"\t";
    s.pop();  
  }
  return 0;
}
