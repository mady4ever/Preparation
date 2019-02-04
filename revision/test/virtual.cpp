#include<iostream>
using namespace std;
//abstract class.
class virtual_base{
    public:
    //pure virtual function
    virtual int add(int a,int b)=0;
};
class derived: public virtual_base{
    public:
    int add(int a, int b){ return a+b;}
};
int main()
{
  virtual_base *b = new derived();
  cout<<b->add(10,20);
  return 0;
}
