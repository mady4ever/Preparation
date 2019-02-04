#include<bits/stdc++.h>
using namespace std;
#define ALPHA 26
typedef struct Node{
    bool isEnd;
    Node *children[ALPHA];
}Node;
Node *makeNode(void)
{
  Node *t = (Node *)malloc(sizeof(Node));
  if(t)
  {
    t->isEnd = false;
    for(int i=0;i<ALPHA;i++)
      t->children[i] = NULL;    
    return t;
  }
  return NULL;
}
Node *insert(Node *root, string input)
{
  if(root == NULL)
  {
     root = makeNode();
  }
  Node *t = root;
  //int count = 0;
  //while(count < input.length() && t!=NULL)
  //{
  //  cout<<input[count]<<endl;
  //  int index = input[count] - 'a'; 
  //  if(t->children[index]== NULL)
  //  {
  //     t->children[index] = makeNode();
  //  }
  //  t = t->children[index];
  //  count++;
  //}
  //t->children[input[count-1]-'a']->isEnd = true;
  ////return root;
  for(int i=0;i<input.length();i++)
  {
    int index = input[i] - 'a';
    if(t->children[index] == NULL)
    {
       t->children[index] = makeNode();
    }
    t = t->children[index];
  }
  t->isEnd = true;
  return root;
}
bool search(Node *root, string input)
{
   if(root == NULL)
     return false;
   //int c = 0;
   //Node *t = root;
   //while(c<input.length() || t!=NULL)
   //{
   //  int index = input[c] - 'a';
   //  if(t->children[index])
   //  {
   //     t = t->children[index];
   //  }
   //  else
   //  {
   //      return false;
   //  }
   //  c++;
   //}
   //return t->children[input[c-1]-'a'];
   Node *t = root;
   for(int i=0;i<input.length();i++)
   {
     int index = input[i]-'a';
     if(t->children[index]==NULL)
       return false;
     t = t->children[index]; 
   }
   return t && t->isEnd;
}
void travers(Node *root, string output)
{
   if(root == NULL)
   {
      //cout<<output<<endl;
      return;
   }
   for(int i=0;i<ALPHA;i++)
   {
      if(root->children[i])
      {
        //output = output + char(i+'a');
        if(root->children[i]->isEnd)
        {            
            string out(output + char(i+'a'));
            cout<<out<<endl;
            //return;
        }
        travers(root->children[i],output + char(i+'a'));
      }
   }
}
int main()
{
  Node *t = makeNode();
  t = insert(t,"abc");
  t = insert(t,"abcd");
  t = insert(t,"xyz");
  t = insert(t,"mahendra");
  t = insert(t,"mah");
  if(search(t,"abc"))
  {
     cout<<"Present";
  }
  else
    cout<<"Not Present";
  cout<<endl;
  travers(t,"");
  return 0;
}
