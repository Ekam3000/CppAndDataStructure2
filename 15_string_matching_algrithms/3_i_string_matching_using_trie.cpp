#include<bits/stdc++.h>
using namespace std;

struct trie
{
    trie *nxt[26];
  //  bool ended;
    trie()
    {
        for(int i=0;i<26;i++)
        {
          nxt[i] = NULL;
        }
       // ended= false;

    }
};
trie *root;
void insert(string s)
{
 trie* cur =root;
 for(int i=0; i< s.size();i++)
 {
    if(cur->nxt[s[i]-'a']==NULL)
    {
        cur->nxt[s[i]-'a'] =new trie();
    }
    cur= cur->nxt[s[i]-'a'];
 }
 //cur pointer will be on the last node
 //cur-> ended =true; 
}
bool in_trie(string s)
{
    trie *cur =root;
    for(int i=0; i< s.size();i++)
 {
    if(cur->nxt[s[i]-'a']==NULL)
    {
       return false;
    }
    cur= cur->nxt[s[i]-'a'];
 }
 // return cur->ended;
 return true;

}
int main()
{
root= new trie();
/*insert("apaar");
insert("vishal");
insert("kamal");
insert("rahul");
insert("kartik");
insert("saurabh");
*/

    string text ="abaacadbacad";
    string pat ="aaca";
    int n =text.size();
    int m=pat.size();
    for(int i=0;i<n;i++)
    {
     insert(text.substr(i));
    }
if(in_trie(pat))
{
    cout<<"yes found\n";
}
else
{
 cout<<"not found";
}
}