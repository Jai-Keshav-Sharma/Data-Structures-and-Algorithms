#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // HELPER FUNCTION FOR INSERT WORD
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // adding character
        int index = word[0] - 'A';
        TrieNode *child;

        // if already present
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        { // if not present
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    // INSERT A WORD
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // HELPER FUNCTION FOR SEARCH WORD()
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // if present
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    // SEARCH A WORD
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("TIME");
    t->insertWord("DO");

    // present or not
    cout << "present or not : " << t->searchWord("ABCD") << endl;
    cout << "present or not : " << t->searchWord("TIM") << endl;
    cout << "present or not : " << t->searchWord("DO") << endl;

    return 0;
}