#include<iostream>
using namespace std;
template <class T>
T add(T a, T b)
{
  return a+b;
}
int main()
{
  cout<<add(10,20)<<endl;
  cout<<add(1.5,2.0)<<endl;
  return 0;
}
