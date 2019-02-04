#include<bits/stdc++.h>
using namespace std;
void tower(int n, char from , char to, char buf)
{
   if(n==1)
   {
     cout<<n<<" "<<from<<" "<<to<<endl;
     return;
   }
   tower(n-1,from, buf, to);
   cout<<n<<" "<<from<<" "<<to<<endl;
   tower(n-1,buf, to, from);
}
int main()
{
  tower(3,'A','C','B'); 
  return 0;
}
