/*
Boolean Evaluation: Given a boolean expression consisting of the symbols 0 (false), 1 (true), & (AND), I (OR), and /\ (XOR), and a desired boolean result value result, implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result. 
The expression should be fully parenthesized (e.g., ( 0) A( 1)) but not extraneously (e.g., ( ( ( 0)) /\ ( 1)) ). 
EXAMPLE countEval("l/\01011", false) -> 2 countEval("0&0&0&1All0", true)-> 10

Some theory:

Consider an expression like 0"0&0"111 and the target result true. How can we break down countEval( 0"0&0"111, true) into smaller problems? We could just essentially iterate through each possible place to put a parenthesis

countEval(0A0&0Alll, true)= countEval(0/\0&0/\lll where paren around char 1, true) + countEval(0/\0&0/\lll where paren around char 3, true) + countEval(0/\0&0/\lll where paren around char S, true) + countEval(0/\0&0/\lll where paren around char 7, true) Now what? Let's look at just one of those expressions-the paren around char 3. This gives us ( 0A0)&( 0/\1 ). In order to make that expression true, both the left and right sides must be true. So: left= "0"0" right = "0/\111" countEval(left & right, true)= countEval(left, true)* countEval(right, true) The reason we multiply the results of the left and right sides is that each result from the two sides can be paired up with each other to form a unique combination. Each of those terms can now be decomposed into smaller problems in a similar process. What happens when we have an "l"(OR)? Or an"A"(XOR)? 

If it's an OR, then either the left or the right side must be true-or both. countEval(left I right, true) countEval(left, true) * countEval(right, false) + countEval(left, false)* countEval(right, true) + countEval(left, true) * countEval(right, true) If it's an XOR, then the left or the right side can be true, but not both. countEval(left /\ right, true)= countEval(left, true)* countEval(right, false) + countEval(left, false) * countEval(right, true) What if we were trying to make the result false instead? We can switch up the logic from above: countEval(left & right, false) countEval(left, true) * countEval(right, false) + countEval(left, false) * countEval(right, true) countEval(left right, false) countEval(left A right, false) + countEval(left, false)* countEval(right, false) countEval(left, false) * countEval(right, false) countEval(left, false)* countEval(right, false) + countEval(left, true) * countEval(right, true) Alternatively, we can just use the same logic from above and subtract it out from the total number of ways of evaluating the expression. totalEval(left) = countEval(left, true)+ countEval(left, false) totalEval(right) = countEval(right, true)+ countEval(right, false) totalEval(expression) = totalEval(left) * totalEval(right) countEval(expression, false)= totalEval(expression) - countEval(expression, true)

similarly check it out from following link
https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
*/
#include<bits/stdc++.h>
using namespace std;
bool evalBool(char input)
{
  //cout<<"input :"<<input<<endl;
  if(input == '1')
   return true;
  else
   return false;
}
int countWays(string input,bool result)
{
  //cout<<input<<"\t"<<result<<endl;
  if(input.length()==0)
     return 0;
  if(input.length()==1)
  {
    return (input.compare("1")==0 && result) || (input.compare("0")==0 && !result) ? 1 : 0;
  }
  int ways=0;
  for(int i=1;i<input.length();i=i+2)
  {
    char ch = input[i];
    //cout<<"ch :"<<ch<<endl;
    string left = input.substr(0,i);
    string right = input.substr(i+1,input.length());
    //cout<<"left: "<<left<<"\t";
    //cout<<"right: "<<right<<"\n"; 
   
    // left and right sub expression evoluations.
    int leftTrue   = countWays(left,true);
    int leftFalse  = countWays(left,false);
    int rightTrue  = countWays(right,true);
    int rightFalse = countWays(right,false);
    //cout<<leftTrue<<"\t"<<leftFalse<<"\t"<<rightTrue<<"\t"<<rightFalse<<endl;
    int total = (leftTrue + leftFalse)*(rightTrue + rightFalse);
    
    //cout<<"total :"<<total<<endl;  
  
    int totalTrue = 0;
    if(ch == '^') //xor is true when both side are different.
    {
       totalTrue = (leftTrue * rightFalse) + (leftFalse * rightTrue);
    }
    else if(ch == '|')
    {
       totalTrue = (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
    }
    else// if(ch == '&') // & is true when both are true.
    {
       totalTrue = (leftTrue * rightTrue);
    }
     totalTrue = result  ? totalTrue : (total - totalTrue);    
    ways+= totalTrue;
  }
  //cout<<"ways :"<<ways<<endl;
  return ways;
}

int catalan(int num)
{
  int cat[num+1];

  for(int i=0;i<=num;i++)
    cat[i] = 0;
  cat[0]=1;
  cat[1]=1;
  for(int i=2;i<=num;i++)
  {
     for(int j=0;j<i;j++)
       cat[i]+=cat[j]*cat[i-j-1];
  }
  return cat[num];
}
int numberofOperators(string input)
{
  int c=0;
  for(int i=0;i<input.length();i++)
  {
     if(input[i] == '^' || input[i] == '&' || input[i]=='|')
       c++;
  }
  return c;
}
int countWaysOpti(string input,bool result,unordered_map<string,int> &mp)
{
  //cout<<input<<"\t"<<result<<endl;
  if(input.length()==0)
     return 0;
  if(input.length()==1)
  {
    return (input.compare("1")==0 && result) || (input.compare("0")==0 && !result) ? 1 : 0;
  }
  if(mp.count(input+to_string(result))>0)
    return mp[input+to_string(result)];
  int ways=0;
  for(int i=1;i<input.length();i=i+2)
  {
    char ch = input[i];
    //cout<<"ch :"<<ch<<endl;
    string left = input.substr(0,i);
    string right = input.substr(i+1,input.length());
    //cout<<"left: "<<left<<"\t";
    //cout<<"right: "<<right<<"\n";

    // left and right sub expression evoluations.
    int leftTrue   = countWaysOpti(left,true,mp);
    int leftFalse  = catalan(numberofOperators(left))-leftTrue;//countWaysOpti(left,false,mp);
    int rightTrue  = countWaysOpti(right,true,mp);
    int rightFalse = catalan(numberofOperators(right))-rightTrue;//countWaysOpti(right,false,mp);
    //cout<<leftTrue<<"\t"<<leftFalse<<"\t"<<rightTrue<<"\t"<<rightFalse<<endl;
    int total = (leftTrue + leftFalse)*(rightTrue + rightFalse);

    //cout<<"total :"<<total<<endl;
    int totalTrue = 0;
    if(ch == '^') //xor is true when both side are different.
    {
       totalTrue = (leftTrue * rightFalse) + (leftFalse * rightTrue);
    }
    else if(ch == '|')
    {
       totalTrue = (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
    }
    else// if(ch == '&') // & is true when both are true.
    {
       totalTrue = (leftTrue * rightTrue);
    }
     totalTrue = result  ? totalTrue : (total - totalTrue);
    ways+= totalTrue;
  }
  mp[input+to_string(result)] = ways;
  //cout<<"ways :"<<ways<<endl;
  return mp[input+to_string(result)];
}
 
int main()
{
  string operations = "1^0&1";//"1|1&0^1";//"l^0|0|1"; //l^0|0|1
  cout<<countWays(operations,true);
  unordered_map<string,int> mp;
  cout<<countWaysOpti(operations,true,mp);
  cout<<endl;
  for(auto i:mp)
  {
     cout<<i.first<<"\t"<<i.second<<endl;
  }
  //cout<<evalBool('1');
  return 0;
}
