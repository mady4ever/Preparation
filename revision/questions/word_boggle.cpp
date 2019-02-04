/*
  https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
  https://www.geeksforgeeks.org/boggle-set-2-using-trie/
*/
#include<bits/stdc++.h>
using namespace std;
#define M 3
#define N 3
#define NB 8
bool issafe(char bog[M][N], int r, int c)
{
   //cout<<"issafe :"<<r<<"\t"<<c<<endl;
   if(r <0 || c <0 || r> M || c> N)
      return false;
   return true;
}
bool isPresent(char bog[M][N],string word, int r, int c, int index)
{
     //cout<<r<<"\t"<<c<<endl;
     if(word.length()==index)
        return true;
     if(word.length() < index)
        return false;
     // -1-1   -10   -11
     // 
     //  0-1    00    01
     //
     //  1-1    10    11
     int rr[] = {1,-1,-1,-1,0,0,1,1,0};
     int cc[] = {1,-1,0,1,-1,1,-1,0,0};
     for(int i=0;i<=NB;i++)
     {
        int xx = r + rr[i];
        int yy = c + cc[i];
        if(issafe(bog,xx,yy) && bog[xx][yy] == word[index])
        {
           //cout<<bog[xx][yy]<<"\t"<<word[index]<<endl;
           if(isPresent(bog,word,xx,yy,index+1))
           {
              return true;
           }
        }
     }
     return false;
}
bool find(char bog[M][N], int &r, int &c, string word)
{
   int index =0;
   for(int i=0;i<M;i++)
   {
      for(int j=0;j<N;j++)
      {
         if(word[index] == bog[i][j])
         {
            r = i;
            c = j;
            return true;
         }
      }
   }
   return false;
}
int main()
{
  char boggle[M][N] = {{'G','I','Z'}, 
                       {'U','E','K'}, 
                       {'Q','S','E'}};
  string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"}; 
  int n = sizeof(dictionary)/sizeof(dictionary[0]); 
  //cout<<isPresent(boggle,dictionary[2],2,0,0);
  for(int i=0;i<n;i++)
  {
    int r =0; 
    int c =0;
    if(find(boggle,r,c,dictionary[i]) && isPresent(boggle,dictionary[i],r,c,0))
    {
      cout<<dictionary[i]<<endl;
    }
  } 
  return 0;
}
