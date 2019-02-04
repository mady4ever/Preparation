#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
   //priority_queue<int, vector<int>, greater<int>> pq; //min heap.
   priority_queue<int> pq; // max heap.
   pq.push(100);
   pq.push(10);
   pq.push(20);
   while(!pq.empty())
   {
      cout<<pq.top()<<"\n";
      pq.pop();
   }
   cout<<pq.size();
   return 0;
}
