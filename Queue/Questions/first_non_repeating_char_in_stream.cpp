#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the first non-repeating character in a stream of characters.
 * 
 * This function takes a string as input and returns a new string where each character 
 * represents the first non-repeating character in the stream up to that point. If there 
 * is no non-repeating character at a certain point, it appends '#' to the result string.
 * 
 * @param s The input string representing the stream of characters.
 * @return A string where each character represents the first non-repeating character 
 *         in the stream up to that point, or '#' if there is no non-repeating character.
 */
string FirstNonRepeating(string &s)
{
    int n = s.length();

    unordered_map<char, int> mpp;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        mpp[ch]++;

        q.push(ch);

        while (!q.empty())
        {
            if (mpp[q.front()] > 1)
            {
                // repeating character
                q.pop();
            }
            else
            {
                // non repeating character
                ans += q.front();
                break;
            }
        }

        if (q.empty())
        {
            // no non-repeating character
            ans += '#';
        }
    }
    return ans;
}