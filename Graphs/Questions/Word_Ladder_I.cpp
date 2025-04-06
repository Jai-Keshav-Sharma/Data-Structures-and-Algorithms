// LeetCode 127. Word Ladder

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the shortest transformation sequence from the beginWord to the endWord
 *        such that only one letter can be changed at a time and each transformed word
 *        must exist in the given wordList.
 * 
 * @param beginWord The starting word of the transformation sequence.
 * @param endWord The target word of the transformation sequence.
 * @param wordList A vector of strings containing the list of valid words for transformation.
 * @return int The length of the shortest transformation sequence. Returns 0 if no such sequence exists.
 * 
 * @details
 * The function uses a breadth-first search (BFS) approach to explore all possible transformations
 * from the beginWord to the endWord. It maintains a queue to track the current word and the number
 * of steps taken to reach it. An unordered_set is used to store the wordList for efficient lookup
 * and to mark words as visited by erasing them from the set.
 * 
 * The algorithm iterates through each character of the current word and tries replacing it with
 * every letter from 'a' to 'z'. If a valid transformation is found (i.e., the transformed word
 * exists in the set), it is added to the queue for further exploration. The process continues
 * until the endWord is found or the queue becomes empty.
 * 
 * Time Complexity: O(M * N), where M is the length of each word and N is the size of the wordList.
 * Space Complexity: O(N), for the queue and the unordered_set.
 */
int ladderLength(string beginWord, string endWord,
                 vector<string> &wordList)
{
    int n = wordList.size();

    queue<pair<string, int>> q;
    //            |      |
    //          word    steps
    q.push({beginWord, 1});

    // set to store and update list of words
    unordered_set<string> st(wordList.begin(), wordList.end());
    // removing beginword from list as its already been found
    st.erase(beginWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        // found the endWord ?
        if (word == endWord)
            return steps;

        // checking every possible combination
        for (int i = 0; i < word.length(); i++)
        {
            // storing the original character before trying out different
            // combos
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // a word from the given list is found
                if (st.find(word) != st.end())
                {
                    st.erase(word); // remove it from list
                    q.push({word, steps + 1});
                }
            }
            // replacing the original letter in its place
            word[i] = original;
        }
    }
    return 0;
}