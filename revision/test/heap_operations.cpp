#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> v)
{
   for(auto i: v)
     cout<<i<<"\t";
   cout<<endl;
}
int main()
{
  vector<int> v = {1,2,3,4,0,-1,-10};
  print(v);
  make_heap(v.begin(),v.end());
  print(v);
  if(is_heap(v.begin(),v.end()))
    cout<<endl<<"it's  a Heap\n";
  cout<<v.front()<<endl;
  pop_heap(v.begin(),v.end());
  print(v);
  cout<<v.front()<<endl;
  v.push_back(-100);
  push_heap(v.begin(),v.end());
  print(v);
  sort_heap(v.begin(),v.end());
  print(v);
  if(is_heap(v.begin(),v.end()))
    cout<<"It's a Heap";
  cout<<"It's  not a Heap";
  return 0;
}
