#include<bits/stdc++.h>
using namespace std;
int oper(char op, int one , int two)
{
    cout<<op<<one<<two<<endl;
    if(op == '+')
        return one + two;
    else if (op == '-')
        return one - two;
    else if (op == '*') 
        return one * two;
    else 
        return one / two;
}
void evaluate(char* s)
{
  //if(s.empty())
  // return;
  stack<int> st;
  for(int i=0;i<8;i++)
  {
     if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
     {
       cout<<s[i]<<endl;
       st.push(s[i] - '0');
       continue;
     }
     else
     {      
       char op = st.top();
       cout<<"operator :"<<op<<endl;
       st.pop();
       if(st.empty())
         return;
       int one = int(st.top() - '0');
       st.pop();
       if(st.empty())
         return;
       int two = int(st.top() - '0');
       st.pop();
       int result = oper(op,one,two);
       cout<<"result :"<<result<<endl; 
       st.push(result);
     }     
  }
  cout<<st.empty() == false ? st.top():0;
  st.pop();
}
int main()
{
  evaluate("231*+9-");
  return 0;
}
