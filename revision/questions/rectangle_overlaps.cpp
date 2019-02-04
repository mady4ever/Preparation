/*
   rectangle not overlaps in case of 1] one is above another or 
                                     2] one is left side of the other.
   otherwise they overlap.
   https://www.geeksforgeeks.org/find-two-rectangles-overlap/
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct Point
{
   int x;
   int y;
}Point;
bool isoverlap(Point l1, Point r1, Point l2, Point r2)
{
    //one is above another.
    if(r2.y > l1.y || r1.y > l2.y)
      return false;
    // one is side of the other.
    if(r1.x < l2.x || r2.x< l1.x)
      return false;
    return true;
}
int main()
{
  Point l1 = {0, 10}, r1 = {10, 0}; 
  Point l2 = {5, 5}, r2 = {15, 0}; 
  if (isoverlap(l1, r1, l2, r2)) 
      printf("Rectangles Overlap"); 
  else
      printf("Rectangles Don't Overlap"); 
  return 0;
}
