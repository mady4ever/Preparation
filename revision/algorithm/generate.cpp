#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
int main()
{
   int a[]={10,20,30,40,50};
   int b[5];
   srand(time(NULL));
   generate(begin(b),end(b),[](){ return rand()%100;});
   for(auto i: b)
     cout<<i<<"\t";
   return 0;
}

