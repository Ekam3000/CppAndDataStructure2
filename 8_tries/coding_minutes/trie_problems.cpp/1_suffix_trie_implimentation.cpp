#include <iostream>
#include <unordered_map>
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
class SuffixTrie
{
    Node *root;
    
public:
    SuffixTrie()
    {
        root = new Node('\0'); // here root node is storing NUlL character in it.
    
    }
    void insert_helper(string word)
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

    bool find(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char c = w[i];
            if (temp->children.count(c) == 0)
            {
                return false;
            }
            else
            {
                temp = temp->children[c];
            }
        }
        return temp->terminal;
    }
    void insert( string word)
    {
      // pick all the substrings from (i, eos) and insert_helper
      for(int i = 0; word[i] != '\0'; i++) 
      {
        insert_helper(word.substr(i));
      }
    }
};

int main()
{
    // simplified suffix trie
    string input ="hello";
    char suffixes[][10]={"lo","ell","hello"};
    SuffixTrie t;
    t.insert(input);
    for(auto sf : suffixes)
    {
        if(t.find(sf))
        {
         cout<<"yes ";
        }
        else
        {
            cout<<"no ";
        }
    }
   
    return 0;
}
