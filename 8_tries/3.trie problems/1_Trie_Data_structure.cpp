// prefix tree ===> trie. it is called prefix becoz two words or more words will have the same prefix.
// so we can insert in trie , search a word in trie.

// a node will consists of three node -- data, hashmap (which will store the address of other nodes which are linked with it).
// a bool variable to indicate whether this node is terminal or not.
// and  this tree is also called generic tree/ n-ary tree.
// to store a phonebook --> which will used , a trie or a hashmap.
// if their are fewer contacts then hashmap is is the better option .. as the number of contacts are going to increase, the number of collisions in the hashmap are also going to increase so it may lead to degradation of the performance. so if the data is huge go with the trie part.
// the time taken for any opeartion is equal to the length of the word.
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
class Trie
{
    Node *root;
    int cnt;
public:
    Trie()
    {
        root = new Node('\0'); // here root node is storing NUlL character in it.
        cnt = 0;
    }
    void insert(char *w)
    {
        Node *temp = root; // temp node will moves further and points to further next and next node.
        for (int i = 0; w[i] != '\0'; i++)
        {
            char c = w[i];
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
};

int main()
{
    Trie t;
    char words[][10] = {"a", "hello", "not", "news", "apple"};
    char w[10];
    cin >> w;

    for (int i = 0; i < 5; i++)
    {
        t.insert(words[i]);// while sending elements of row zero.
    }
    if (t.find(w))
    {
        cout << "Present";
    }
    else
    {
        cout << "Absent";
    }
    return 0;
}
