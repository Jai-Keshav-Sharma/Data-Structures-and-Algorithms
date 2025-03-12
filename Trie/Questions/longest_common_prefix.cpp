// LeetCode 14. Longest Common Prefix

#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 ---------------------- USING TRIE ----------------------- NOT OPTIMAL AT ALL
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }

        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch) { root = new TrieNode(ch); }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // adding character
        int index = word[0] - 'a';
        TrieNode *child;

        // if already present
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        { // if not present
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    // INSERT A WORD
    void insertWord(string word) { insertUtil(root, word); }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // go ahead
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
                break;
        }
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie *t = new Trie('\0');

        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].length() == 0)
                return "";
            t->insertWord(strs[i]);
        }

        string first = strs[0];
        string ans = "";

        t->lcp(first, ans);
        return ans;
    }
};

// APPROACH 2 ---------------------------- BETTER THAN ABOVE APPROACH IN TERMS OF SPACE AND SPEED ------------------------

class Solution
{
public:
    /**
     * @brief Finds the longest common prefix string amongst an array of strings.
     * 
     * This function uses a Trie data structure to insert all the strings from the input vector.
     * It then computes the longest common prefix by traversing the Trie.
     * 
     * @param strs A vector of strings for which the longest common prefix is to be found.
     * @return A string representing the longest common prefix. If there is no common prefix, an empty string is returned.
     */
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";

        for (int i = 0; i < strs[0].size(); i++)
        {
            char ch = strs[0][i];
            bool match = true;

            for (int j = 1; j < strs.size(); j++)
            {
                // not match
                if (i > strs[j].size() || ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }

            if (match == false)
            {
                break;
            }
            else
            {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
