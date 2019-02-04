#include<iostream>
#include<queue>
#include<time.h>
#include<vector>
using namespace std;
int main()
{
  priority_queue<int , vector<int>, greater<int>> pq;//={10,1,2,3,4,100};
  srand (time(NULL));
  for(int i=0;i<10;i++)
    pq.push(rand()*100%10);
  while(!pq.empty())
  {
    cout<<pq.top()<<"\t";
    pq.pop();
  }
  return 0;
}
