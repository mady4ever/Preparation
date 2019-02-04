#include<iostream>
using namespace std;
class base{
  int a,b;
  public:
  base(void){a=1;b=3;}
  int area(void){ return a*b;}  
};
class derived: public base{
   int a,b;
   public:
   derived(void)
   {
     base(); 
     a = b=5;
   }
   int area(void){return a+b;};
};
int main()
{
  base *d = new derived();
  cout<<d->area();
  return 0;
}
