/*
  https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
  Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/
#include<bits/stdc++.h>
using namespace std;
int knapSack(int val[],int wt[],int n,int W,int i)
{
  cout<<i<<"\t"<<W<<endl;
  if(i>n) return 0; // if out of range.
  if(wt[i] > W)
    return knapSack(val,wt,n,W,i+1);
  else
    return max(val[i] + knapSack(val,wt,n,W-wt[i],i+1), knapSack(val,wt,n,W,i+1)); // value included and value excluded. 
}
int knapSackWithMemoization(int val[],int wt[],int n,int W,int i,unordered_map<string,int> &mp)
{
  cout<<i<<"\t"<<W<<endl;
  if(i>n) return 0;
  if(wt[i] > W)
    return knapSackWithMemoization(val,wt,n,W,i+1,mp);
  string key = to_string(char(i))+ char('0' + W);
  if(mp.count(key)>0)
    return mp[key];
  mp[key] = max(val[i] + knapSackWithMemoization(val,wt,n,W-wt[i],i+1,mp), knapSackWithMemoization(val,wt,n,W,i+1,mp));
  return mp[key];
}
int main()
{
  int val[] = {60, 100, 120}; 
  int wt[] = {10, 20, 30};
  int  W = 50;
  int n = sizeof(val)/sizeof(val[0]);
  cout<<knapSack(val,wt,n,W,0);
  unordered_map<string,int> mp;
  cout<<endl;
  cout<<knapSackWithMemoization(val,wt,n,W,0,mp);
  return 0;
}
