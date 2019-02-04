#include<iostream>
using namespace std;
static int a = 11;
int main()
{
   //int a=0;
   for(int i=0;i<10;i++)
   {
     cout<<a<<"\t";
     a+=i;
   }
   return 0;
}
