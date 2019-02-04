#include<iostream>
using namespace std;
int print(int mat[][3])
{
   for(int r=0;r<3;r++)
   {
     for(int c=0;c<3;c++)
     {
       cout<<mat[r][c]<<"\t";
     }
     cout<<endl;
   }
}
int main()
{
  int mat[3][3]={{1,2,3},
                 {4,5,6},
		 {7,8,9}};
  print(mat);
  /*
  for(int r=0;r<3;r++)
  {
    for(int c=0;c<3;c++)
    {
      cout<<mat[r][c]<<"\t";
    }
    cout<<endl;
  }
  */
  return 0;
}
