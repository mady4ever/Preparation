/*
 https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
 1] use max and min heap to keep the running median.
 2] max element goes to min heap
 3] min element goes to max heap.
 4] make sure to balance the heap.
*/
#include<bits/stdc++.h>
using namespace std;
#define MaxHeap priority_queue<int>
#define MinHeap priority_queue<int,vector<int>,greater<int>>

int diff(MaxHeap l, MinHeap r)
{
  return l.size() - r.size();
}
void MedianUtil(int e, int &m, MaxHeap &l, MinHeap &r)
{
  int d = diff(l,r);
  switch(d)
  {
    case 1:
       if(e < m) // if this is less than running median.
       {
	  r.push(l.top());
	  l.pop();
	  l.push(e);
       }
       else
       {
         r.push(e);
       }
       m = (l.top() + r.top())/2;
       break;
    case -1:
       if(e < m) // element goes to max heap.
       {
         l.push(e);	 
       }
       else
       {
         l.push(r.top());
	 r.pop();
	 r.push(e);
       }
       m = (l.top() + r.top())/2;
       break;
    case 0:
       if(e < m)
       {
         l.push(e);
	 m = l.top();
       }
       else
       {
         r.push(e);
	 m = r.top();
       }
       break;
    default:
     cout<<"Invalid Flow"<<endl;
  }
}
void runningMedian(int a[],int s)
{
  int m = 0;
  MaxHeap l;
  MinHeap r;
  for(int i=0;i<s;i++)
  {
    MedianUtil(a[i],m,l,r);
    cout<<m<<endl;
  }
}
int main()
{
  int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
  int s = sizeof(A)/sizeof(A[0]);
  runningMedian(A,s);
  return 0;
}
