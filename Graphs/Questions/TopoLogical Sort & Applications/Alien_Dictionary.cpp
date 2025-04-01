#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // TOPOLOGICAL SORT FUNCTION
    void topoSort(vector<vector<int>> &adj, vector<int> &topo)
    {
        int n = adj.size();
        vector<int> indeg(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indeg[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto adjNode : adj[node])
            {
                indeg[adjNode]--;

                if (indeg[adjNode] == 0)
                {
                    q.push(adjNode);
                }
            }
        }

        // if any cyclic dependency is present, the language is invalid
        // and empty string must be returned
        if (topo.size() != n)
        {
            topo.clear();
        }
    }

public:
    /**
     * @brief Determines the order of characters in an alien language based on a given dictionary.
     * 
     * This function takes a list of words from an alien dictionary and determines the order
     * of characters in the alien language. It constructs a directed graph based on the 
     * lexicographical order of characters in the dictionary and performs a topological sort 
     * to derive the character order.
     * 
     * @param dictionary A vector of strings representing the alien dictionary. Each string 
     *        is a word in the alien language, and the order of words defines the lexicographical 
     *        order of characters.
     * 
     * @return A string representing the order of characters in the alien language. If the 
     *         dictionary is invalid (e.g., a prefix condition is violated), an empty string 
     *         is returned.
     * 
     * @note The function assumes that all characters in the dictionary are lowercase English 
     *       letters ('a' to 'z').
     * 
     * @details
     * - Constructs an adjacency list to represent the directed graph of character precedence.
     * - Compares adjacent words in the dictionary to determine character precedence.
     * - If a prefix condition is violated (e.g., a longer word appears before its prefix), 
     *   the function returns an empty string.
     * - Performs a topological sort on the graph to determine the character order.
     * - Converts the topological order into a string and returns it.
     */
    string foreignDictionary(vector<string> &dictionary)
    {
        int n = dictionary.size();

        vector<vector<int>> adj(26);
        int l = 0;
        int r = 1;
        bool found = false;

        // making adjacency list from the given dictionary
        while (r < n)
        {
            string first = dictionary[l];
            string second = dictionary[r];
            int minlen = min(first.length(), second.length());

            for (int i = 0; i < minlen; i++)
            {
                if (first[i] != second[i])
                {
                    adj[first[i] - 'a'].push_back(second[i] - 'a');
                    found = true;
                    break;
                }
            }

            // if first string is greater than second string
            // and any non-same character has not been found yet, then given language is not valid
            if (!found && first.length() > second.length())
            {
                return "";
            }

            l++;
            r++;
        }

        vector<int> topo;
        topoSort(adj, topo);
        string ans = "";

        // converting topo vector back to string
        for (auto it : topo)
        {
            ans += char(it + 'a');
        }

        return ans;
    }
};
