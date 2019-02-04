#include<bits/stdc++.h>
using namespace std;
void nge(int a[], int s)
{
  int cur = 0;
  stack<int> st;
  st.push(a[0]);
  for(int i=1;i<s;i++)
  {
    cur = a[i];
    if(st.empty())
    {
      st.push(cur);
      continue;  
    }
    while(!st.empty() && st.top() < cur)
    {
      cout<<st.top()<<" "<<cur<<endl;
      st.pop();
    }
    st.push(cur);
  }
  while(!st.empty())
  {
     cout<<st.top()<<" "<<-1<<endl;
     st.pop();
  }
}
int main()
{
  int arr[] = {11, 13, 21, 3}; 
  int s = sizeof(arr) / sizeof(arr[0]); 
  nge(arr, s);
  return 0;
}
