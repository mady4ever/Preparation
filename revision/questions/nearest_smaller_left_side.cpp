/*
   https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
*/
#include<bits/stdc++.h>
using namespace std;
void nearestSmaller(int a[], int s)
{
   stack<int> st;
   for(int i=0;i<s;i++)
   {
     while(!st.empty() && st.top() > a[i])
        st.pop();
     if(st.empty())
      cout<<"-\t";
     else
      cout<<st.top()<<"\t";
     st.push(a[i]);
   }
}
int main()
{
   int a[] = {1,2,3,4,5,6,7};
   int s = sizeof(a)/sizeof(a[0]);
   nearestSmaller(a,s);
   return 0;
}
