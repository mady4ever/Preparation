#include<iostream>
#include<string>
using namespace std;

int add(int a[], int size)
{
   int temp=0;
   for(int i=0;i<size;i++)
   {
     temp+=a[i];
   }
   return temp;
}
int main()
{

  std::cout<<"Hello This is cpp";
  int a[] = {1,2,3,4,5};
  int size = sizeof(a)/sizeof(int);
  std::cout<<add(a,size);
  //string test_string = "Mahendra Patel";
  //std::cout<<test_string;
  return 0;
}
