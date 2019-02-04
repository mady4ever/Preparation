/*
  https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
*/
#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b)
{
   string x = a.append(b);
   string y = b.append(a);
   return x.compare(y) >0 ? true:false; 
}
void biggestNumber(vector<string> input)
{
   auto comp = [](string a,string b){ string x = a.append(b); string y = b.append(a); return x.compare(y)>0?1:0;};
   sort(input.begin(),input.end(),comp);
   string result = "";
   for(auto i: input)
   result+=i;
   cout<<result<<endl;
}
int main()
{
  vector<string> arr={"54","546","548","60"};
  biggestNumber(arr);  
  return 0;
}
