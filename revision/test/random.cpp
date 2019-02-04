#include<iostream>
#include<ctime>
using namespace std;

int main()
{ 
  srand(time(NULL));
  int i = rand()%10;
  cout<<i<<endl;
  return 0;
}
