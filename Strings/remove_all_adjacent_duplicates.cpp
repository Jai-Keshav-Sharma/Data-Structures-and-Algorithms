class Solution {
public:
    /**
     * @brief Removes all adjacent duplicate characters from the input string.
     * 
     * This function iterates through the input string and uses a stack to keep track of characters.
     * If the current character is the same as the character at the top of the stack, it is removed.
     * Otherwise, the character is pushed onto the stack. After processing all characters, the stack
     * is used to construct the result string in reverse order.
     * 
     * @param s The input string from which adjacent duplicates need to be removed.
     * @return A string with all adjacent duplicates removed.
     */
    string removeDuplicates(string s) {
       stack<char> stk;

       for(char c : s)
       {
        if(!stk.empty() and stk.top() == c)
        {
            stk.pop();
        }
        else
        {
            stk.push(c);
        }
       }

       string result;

       while(!stk.empty())
       {
        result = result + stk.top();
        stk.pop();
       }
       reverse(result.begin(), result.end());
       
       return result;
    }
};