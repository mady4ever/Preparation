#include<iostream>
using namespace std;
class test{
   int a,b,result;
   public:
   test(int aa,int bb):a(aa),b(bb){ cout<<"Inside constructor\n";};
   void add(void)
   { 
      result = a+b;
   }
   void print(void)
   {
     cout<<a<<"\t"<<b<<"\t"<<result<<endl;
   }
   ~test(void)
   {
     cout<<"Inside destructor."<<endl;
   }
};
int main()
{
  test t(10,20);
  t.add();
  t.print();
  return 0;
}
