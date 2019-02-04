#include<iostream>
using namespace std;
class A{
   int a;
   public:
   friend void add(A aa);
   inline void print(void);
};
void add(A aa)
{
   cout<<"\na = "<<aa.a<<endl;
}
void A::print(void)
{
   cout<<this->a<<endl;
}
int main()
{
  A aa;
  A *ptr;
  ptr = &aa;
  aa.print();
  add(aa);
  ptr->print();
  return 0;
}
