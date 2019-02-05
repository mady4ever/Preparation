/*
Theary from cracking the coding interview.
The brute force way to search for a substring S in a larger string B takes O ( s ( b-s)) time, where s is the length of S and b is the length of B. We do this by searching through the first b - s + 1 characters in B and, for each, checking if the next s characters match S. The Rabin-Karp algorithm optimizes this with a little trick: if two strings are the same, they must have the same hash value. (The converse, however, is not true. Two different strings can have the same hash value.) Therefore, if we efficiently precompute a hash value for each sequence of s characters within B, we can find the locations of Sin O(b) time. We then just need to validate that those locations really do match S. For example, imagine our hash function was simply the sum of each character (where space= 0, a= 1, b = 2, and so on). If S is ear and B = doe a re hearing me, we'd then just be looking for sequences where the sum is 24 (e +a+ r). This happens three times. For each of those locations, we'd check if the string really is ear. 



XI. Advanced Topics
If we computed these sums by doing hash(· doe·), then hash ( • oe ·),then hash(· e a·), and soon, we would still be atO(s (b-s)) time. Instead, we compute the hash values by recognizing that hash ( 'oe ') hash ('doe') - code(' d') + code(' '). This takes O(b) time to compute all the hashes. You might argue that, still, in the worst case this will take 0( s ( b-s)) time since many of the hash values could match. That's absolutely true-for this hash function. In practice, we would use a better rolling hash function, such as the Rabin fingerprint. This essentially treats a string like doe as a base 128 (or however many characters are in our alphabet) number. hash('doe') = code('d') * 1282 + code('o') * 1281 + code('e') * 128° This hash function will allow us to remove the d, shift the o and e, and then add in the space. hash('oe ') = (hash('doe') - code('d') * 1282) * 128 + code(' ') This will considerably cut down on the number of false matches. Using a good hash function like this will give us expected time complexity of O(s + b ), although the worst case is 0( sb ). Usage of this algorithm comes up fairly frequently in interviews, so it's useful to know that you can identify substrings in linear time.

optimization in hash function:

In practice, we would use a better rolling hash function, such as the Rabin fingerprint. This essentially treats a string like doe as a base 128 (or however many characters are in our alphabet) number. hash('doe') = code('d') * 1282 + code('o') * 1281 + code('e') * 128° This hash function will allow us to remove the d, shift the o and e, and then add in the space. hash('oe ') = (hash('doe') - code('d') * 1282) * 128 + code(' ') This will considerably cut down on the number of false matches. Using a good hash function like this will give us expected time complexity of O(s + b ), although the worst case is 0( sb ). 

*/
#include<bits/stdc++.h>
using namespace std;
int CharToInt(char ch)
{
   return int(ch-'a');
}
int hashOfString(string input)
{
   int hash=0;
   for(auto i : input)
      hash+=CharToInt(i);
   return hash;
}
int hash_input(string input,int s,int w_s)
{
 int init=0;
 if((s+w_s) > input.length()) return -1;
 for(int i=s;i<(s+w_s);i++)
    init+=CharToInt(input[i]);
 return init;
}
bool isSubstring(string input, string pat)
{

  int hash_code[input.length()+1];
  fill(hash_code,hash_code+input.length()+1,0);
  int pat_len = pat.length();
  int start = pat_len;
  hash_code[0] = hash_input(input,0,pat_len);
  for(int i=1;i<=(input.length()-pat_len);i++)
  {
    hash_code[i] = hash_input(input,i,pat_len);//-CharToInt(input[i-1]);
  }
  int hash_of_pat = hashOfString(pat);
  
  for(int i=0;i<input.length()+1;i++)
  {
    if(hash_code[i] == hash_of_pat)
      cout<<"\nSubstring present :"<<hash_of_pat<<endl;
  }
  for(int i=0;i<input.length();i++)
   cout<<hash_code[i]<<"\t";
  return false;
}
int main()
{
  cout<<isSubstring("mahendra","eha");
  //cout<<"\n"<<hashOfString("ahen");
  return 0;
}
