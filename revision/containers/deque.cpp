#include<iostream>
#include<deque>
using namespace std;
int main()
{
   deque<int> dq = {1,2,3,4,5};
   while(!dq.empty())
   {
     cout<<dq.back()<<"\t";
     dq.pop_back();
     //dq.pop();
   }
   return 0;
}
