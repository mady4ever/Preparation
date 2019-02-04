#include<iostream>
using namespace std;
int add(int &a, int &b)
{
    a+=a+10;
    b+=b+10;
    return a+b;
}
int sub(int *a, int *b)
{
    *a+=*a+100;
    *b+=*b+100;
    return a-b;
}
int main()
{
   int a=0;
   int b=0;
   cout<<add(a,b)<<"\t";
   cout<<a<<"\t"<<b<<endl;
   cout<<sub(&a,&b)<<"\t";
   cout<<a<<"\t"<<b<<endl;
   return 0;
}
