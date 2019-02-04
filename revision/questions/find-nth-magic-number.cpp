/*
  https://www.geeksforgeeks.org/find-nth-magic-number/
*/
#include<bits/stdc++.h>
using namespace std;
void binary_num(int num)
{
   
   int c=0;
   int magic_num = 0;
   while(num)
   {
     int p = num%2;
     //if(p==1)
     cout<<p<<"\t";
     if(p==1)
        magic_num= magic_num + 5*pow(5,c);
     num = num/2;
     c++;
   }
   cout<<magic_num;
   cout<<endl;
}
int main()
{
  for(int i=0;i<=5;i++)
   binary_num(i);
  return 0;
}
