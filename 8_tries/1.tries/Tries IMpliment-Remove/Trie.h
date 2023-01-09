#include "TrieNode.h"
#include <string>

class Trie {
	TrieNode *root; // random pointer pointing to garbage location

	public :
	Trie() {
		root = new TrieNode('\0');
	}

	bool search(TrieNode *root, string word) {
		if(word.size() == 0) {
			return root -> isTerminal; // agar given node ka terminal true return hoga then word exist karta hai
		}
		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index]; // child pointing to roots one of the children early build during insersion  
		}
		else {
			return false;
		}
		// Recursive call
		return search(child, word.substr(1));
	}
	bool search(string word) {
		return search(root, word);
	}


	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true; // WORD INSERSION ENDS.
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index]; // means ek children hai hamare pass jiska data 'a' hai (taking example of and word) supposing 'a' is already a children of root .. then during the formation of word 'and' new child node will directly links to 'a' data node
		}
		else {
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) { // one data argument passed by user..
		insertWord(root, word); // calling two argument function .... helper function
	}
	void removeWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = false; // hum word ke last letter ko false karke return ho jaiye ge  , so agar next time ye word search bhi hua to ..is given word ke last letter hame false hi return kare ga  
			return;
		}
		// Small calculation
		TrieNode *child;
		int index =  word[0] - 'a';
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			// Word not found
			return;
		}
		removeWord(child, word.substr(1));
		// Remove child Node if it is useless
		if(child -> isTerminal == false) {
			for(int i = 0; i < 26; i++) {
				if(child -> children[i] != NULL) {
					return;
				}
			}
			delete child;
			root -> children[index] = NULL;
		}
	}
	void removeWord(string word) {
		removeWord(root, word);
	}

};
