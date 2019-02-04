/*
   https://www.geeksforgeeks.org/minimum-sum-squares-characters-counts-given-string-removing-k-characters/
   idea is to remove the high frequency char's K times and then take the sum of there powers.
   use the max heap to keep the max frequency arrays.
*/
#include<bits/stdc++.h>
using namespace std;
void getmaxsum(string input, int k)
{
   unordered_map<char,int> freq;
   for(int i=0;i < input.length();i++)
   {
     freq[input[i]]++;
   }
   priority_queue<int> mp;
   for(auto i: freq)
   {
      mp.push(i.second);
   }
   while(k>0)
   {
      int t = mp.top();
      t--;
      mp.pop();
      mp.push(t);
      k--; 
   }
   int ans=0;
   while(!mp.empty())
   {
     ans = ans + mp.top()*mp.top();
     mp.pop(); 
   }
   cout<<ans<<endl;
}
int main()
{
  string input = "abccc";
  int k=1;
  getmaxsum(input,k);
  return 0;
}
