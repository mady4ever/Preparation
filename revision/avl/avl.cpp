#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int d; // data in the tree.
    int h; //heaight of tree.
    Node *l,*r;
}Node;
Node *makeNode(int d)
{
   Node *t = (Node *)malloc(sizeof(Node));
   if(t)
   {
      t->d = d;
      t->h = 1;
      t->l = t->r = NULL;
      return t;
   }
   return NULL; //raise exception for memory allocation failed.
}
Node *insert(Node *r, int d)
{
   if(r==NULL)
     return makeNode(d);
   if(d < r->d)
     r->l = insert(r->l, d);
   else
     r->r = insert(r->r, d);
   return r;
}
void inOrder(Node *r)
{
   if(r)
   {
      inOrder(r->l);
      cout<<r->d<<endl;
      inOrder(r->r);
   }
}
Node * popTree(void)
{
    Node *t = insert(NULL,5);
    t = insert(t,4);
    t = insert(t,6);
    t = insert(t,2);
    t = insert(t,8);
    t = insert(t,1);
    t = insert(t,9);
    return t;
}
int height(Node *r)
{
   if(r==NULL)
    return 0;
   return r->h;
}
//
//         y                x
//        / \      RR      / \
//      x    T3    ===>  T1    y   
//     / \                    / \
//    T1  T2                 T2   T3
//
//
//
Node * RightRotate(Node *y)
{
   //cout<<"right rotate"<<endl;
   Node *x = y->l;
   Node *T2 = x->r;

   x->r = y;
   y->l = T2;

   y->h = max(height(y->l),height(y->r)) + 1;
   x->h = max(height(x->l),height(x->r)) + 1;
   return x;
}
Node *LeftRotate(Node *x)
{
   //cout<<"left rotate"<<endl;
   Node *y = x->r;
   Node *T2 = y->l;
   
   y->l = x;
   x->r = T2;

   x->h = max(height(x->l),height(x->r)) + 1;
   y->h = max(height(y->l),height(y->r)) + 1;
   return y;
}
int getDiff(Node *r)
{
   if(r==NULL) return 0;
   return height(r->l) - height(r->r);
}
Node *insertAVL(Node *r, int d)
{
   if(r==NULL)
     return makeNode(d);
   if(d < r->d)
      r->l = insertAVL(r->l,d);
   else if(d > r->d)
      r->r = insertAVL(r->r,d);
   else           //equal key node not allowed in avl.
      return r;

   r->h = max(height(r->l),height(r->r)) + 1;   
   int hd = getDiff(r); // height difference.
  
   if(hd > 1 && d < r->l->d) //if this element goes to left side of the subtree then left left case.
   { 
     return RightRotate(r);
   }
   else if (hd > 1 && d > r->l->d) // left right case. This element goes to left right case.
   {
        r->l = LeftRotate(r->l);
        return RightRotate(r);
   }
   if(hd < -1 && d > r->r->d) //right right case. This element goes to right right case.
   {
       return LeftRotate(r);
   }
   else if(hd < -1 && d < r->r->d) // right left case. This element goes to right left case.
   {
        r->r = RightRotate(r->r);
        return LeftRotate(r);     
   }
   return r;
}
Node *popAVLTree(void)
{
   Node *r = NULL;
   r = insertAVL(r,10);
   r = insertAVL(r,20);
   r = insertAVL(r,30);
   r = insertAVL(r,40);
   r = insertAVL(r,50);
   r = insertAVL(r,25);
   return r; 
}
void preOrder(Node *r)
{
   if(r)
   {
     cout<<r->d<<endl;
     preOrder(r->l);
     preOrder(r->r);
   }
}
int main()
{
  //Node *t = popTree();
  //inOrder(t);
  Node *t = popAVLTree();
  preOrder(t);
  return 0;
}
