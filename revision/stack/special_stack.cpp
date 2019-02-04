#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node(int d1,int m1)
    {
       d = d1; m = m1;
    }
    int d;
    int m;
};
class sstack
{
   stack<Node *> st;
   public:
     void push(int d);
     int pop(void);
     int top(void);
     int getMin(void);
     bool isEmpty(void);
};
void sstack::push(int d)
{
  if(st.empty())
  {
     st.push(new Node(d,d));  
  }
  else
  {
    Node *temp = st.top();
    Node *t = new Node(d, temp->m > d ? d : temp->m);
    st.push(t);
  }
}
int sstack::pop(void)
{
   if(st.empty())
   {
     return INT_MAX; 
   }
   else
   {
     Node *t = st.top();
     st.pop();
     return t->d;
   }
}
int sstack::top(void)
{
   if(st.empty())
   {
      return INT_MAX;
   }
   else
   {
     return st.top()->d;
   }
}
int sstack::getMin(void)
{
   if(st.empty())
   {
     return INT_MAX;
   }
   else
   {
     return st.top()->m; 
   }
}
bool sstack::isEmpty(void)
{
   return st.empty();
}
int main()
{
  sstack *m = new sstack();
  m->push(10);
  m->push(5);
  m->push(20);
  cout<<m->getMin()<<endl;
  cout<<m->top()<<endl;
  cout<<m->isEmpty()<<endl;
  while(!m->isEmpty())
  {
    cout<<m->pop()<<"\t";
  }
  cout<<m->isEmpty()<<endl;
  return 0;
}
