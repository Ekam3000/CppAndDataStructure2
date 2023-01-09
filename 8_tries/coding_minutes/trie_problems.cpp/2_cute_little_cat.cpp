#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    bool terminal;
    char data;
    unordered_map<char, Node *> children;
    Node(char d)
    {
        data = d;
        terminal = false;
    }
};
class Trie
{
    
public:
    Node *root;
    Trie()
    {
        root = new Node('\0'); // here root node is storing NUlL character in it.
    
    }
    void insert(string word)
    {
        Node *temp = root; // temp node will moves further and points to further next and next node.
        for (char c : word)
        {
            if (temp->children.count(c)) // count function checks whether in its hash map char c is there or not
            {
                temp = temp->children[c]; // children[c] equals to node addresss
            }
            else
            {
                Node *n = new Node(c);
                temp->children[c] = n; // storing address of new node in the hashmap of temp..
                temp = n;
            }
        }
        temp->terminal = true;
    }
};
void searchHelper(Trie t, string document, int i, unordered_map<string,bool> &m)
{
Node *temp =t.root;
for(int j=i;j<document.length();j++)
{
    char ch= document[j];
    if(temp->children.count(ch)==0)
    {
        return ;
    }
    temp= temp->children[ch];
    if(temp->terminal)
    {
        // history part
        string out =document.substr(i,j-i+1);
        m[out] = true;
    }
}
return;
}
void documentSearch(string document, vector<string> words)
{
// 1. create a trie of words
Trie t;
for(auto w: words)
{
    t.insert(w);
}
// 2. searching (helper fn)
unordered_map<string,bool>m;
for(int i = 0; i < document.length(); i++)
{
    searchHelper(t,document,i,m);
}
// 3. you can check which words are marked as true inside hashmap
for(auto w: words)
{
    if(m[w])
    {
        cout<<w <<" : True"<<endl;
    }
    else
    {
        cout<<w <<" : False"<<endl;
    }
}
return;
}

int main()
{
    string document ="little cute cat loves to code in c++, java and python";
    vector<string>words={"cute cat","ttle","cat","quick","big"};
    documentSearch(document,words);
}