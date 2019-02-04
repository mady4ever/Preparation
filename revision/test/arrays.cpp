#include<iostream>
using namespace std;
int main()
{
  int a[10]={1,4,3,12,12,1,21,21,11,12};
  int size = sizeof(a)/sizeof(int);
  for(int i=0;i<size;i++)
    cout<<a[i]<<"\t";
  return 0;
}
