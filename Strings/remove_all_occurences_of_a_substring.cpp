class Solution {
public:
    /**
     * @brief Removes all occurrences of a specified substring from a given string.
     * 
     * This function repeatedly searches for the specified substring within the 
     * given string and removes all its occurrences until none are left.
     * 
     * @param s The original string from which the substring will be removed.
     * @param part The substring to be removed from the original string.
     * @return A new string with all occurrences of the specified substring removed.
     */
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 and s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};