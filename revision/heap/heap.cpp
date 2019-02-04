#include<bits/stdc++.h>
using namespace std;
int arr[20];
int size = 20;
int ind = -1;
int parent(int i)
{
  return (i-1)/2;
}
int left(int i)
{
   return (2*i+1);
}
int right(int i)
{
   return (2*i+2);
}
int heapify(int i)
{
   int l = left(i);
   int r = right(i);
   int smallest = i;
   if(i < size && arr[i] < arr[smallest])
       smallest = i;
   if(i < size && arr[r] < arr[smallest])
       smallest = r;
   if(smallest != i)
   {
      swap(arr[i], arr[smallest]);
      heapify(smallest);
   }
}
void heapUp(int i)
{
   while(i!=0 && arr[parent(i)] > arr[i])
   {
      swap(arr[parent(i)], arr[i]);
      i = parent(i);
   }
}
void insert(int v)
{
  if(ind >= size)
    cout<<"\nOverFlow\n";
  
  arr[++ind] = v;
  heapUp(ind);
}
int top(void)
{
   //if(ind  0)
   //  return INT_MAX;
   return arr[0];
}
void reset(void)
{
   ind = -1;
   size = 20;
} 
void print(void)
{
  for(auto i: arr)
   cout<<i<<"\t";
  cout<<endl;  
}
int main()
{
  reset();
  insert(100);
  insert(99);
  insert(155);
  cout<<top()<<endl;
  print();
  cout<<is_heap(arr,arr+2,greater<int>()); // check for is heap
  return 0;
}
