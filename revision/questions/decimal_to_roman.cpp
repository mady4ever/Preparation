/*
  https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
SYMBOL       VALUE
I             1
IV            4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900 
M             1000      
*/
#include<bits/stdc++.h>
using namespace std;
void convertoroman(int num)
{
  string mm[]={"","M","MM","MMM"};
  string cm[]={"","C","CC","CCC","CD","D","DC","DCC","DCC","CM"};
  string xx[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
  string ii[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
  string output;
  output+= mm[num/1000];
  output+=cm[(num%1000)/100];
  //num%=100;
  output+=xx[(num%100)/10];
  output+=ii[num%10];
  cout<<output<<endl;
}
int main()
{
  convertoroman(3549);
  return 0;
}
