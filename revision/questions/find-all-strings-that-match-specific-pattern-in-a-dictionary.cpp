/*
  https://www.geeksforgeeks.org/find-all-strings-that-match-specific-pattern-in-a-dictionary/
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to encode given string 
string encodeString(string str) 
{ 
    unordered_map<char, int> map; 
    string res = ""; 
    int i = 0; 
  
    // for each character in given string 
    for (char ch : str) 
    { 
        // If the character is occurring for the first 
        // time, assign next unique number to that char 
        if (map.find(ch) == map.end()) 
            map[ch] = i++; 
  
        // append the number associated with current 
        // character into the output string 
        res += to_string(map[ch]); 
    } 
  
    return res; 
} 
  
// Function to print all the strings that match the 
// given pattern where every character in the pattern is 
// uniquely mapped to a character in the dictionary 
void findMatchedWords(unordered_set<string> dict, 
                      string pattern) 
{ 
    // len is length of the pattern 
    int len = pattern.length(); 
  
    // encode the string 
    string hash = encodeString(pattern); 
  
    // for each word in the dictionary 
    for (string word : dict) 
    { 
        // If size of pattern is same as size of current 
        // dictionary word and both pattern and the word 
        // has same hash, print the word 
        if (word.length() == len && encodeString(word) == hash) 
            cout << word << " " ; 
    } 
} 
  
// Driver code 
int main() 
{ 
    unordered_set<string> dict = { "abb", "abc", "xyz", "xyy" }; 
    string pattern = "foo"; 
  
    findMatchedWords(dict, pattern); 
  
    return 0; 
}
