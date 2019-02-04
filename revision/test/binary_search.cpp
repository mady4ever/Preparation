#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool bsearch(vector<int> v, int vl)
{
  if(!is_sorted(v.begin(),v.end()))
     return false;
  int l=0;
  int h = v.size();
  while (l<=h)
  {
    int m = (l+h)/2;
    cout<<endl<<m<<endl;
    if(v[m] == vl)
    {
      cout<<"found "<<vl<<endl;
      return true;
    }
    else if(v[l] > v[m])
      l = m;
    else
      h = m;
    if(l==m)
     break;
  }
  return false;
}
bool bsr(vector<int> v, int l, int h,int vl)
{
   
   int mid = (l+h)/2;
   if(l>h)
     return false;
   if(v[mid] == vl)
     return true;
   else if(v[l] <= v[mid])
     return bsr(v,l, mid-1,vl);
   else
     return bsr(v,mid+1,h,vl);
   return false; 
}
int main()
{
  vector<int> v={1,9,2,8,3,7,6,4,8};
  sort(v.begin(),v.end());
  if(binary_search(v.begin(),v.end(),3))
    cout<<"present";
  else
    cout<<"not present";
  cout<<endl<<bsearch(v,3);
  cout<<endl<<bsr(v,0,v.size()-1,3)<<endl;
  return 0;
}
