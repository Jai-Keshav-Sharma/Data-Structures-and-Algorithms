#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;
  return false;
}

/**
 * @brief Checks if a given string contains redundant brackets.
 * 
 * This function takes a string representing a mathematical expression and 
 * determines if there are any redundant brackets in the expression. Redundant 
 * brackets are those which do not affect the result of the expression.
 * 
 * @param s A reference to the input string representing the mathematical expression.
 * @return true if there are redundant brackets in the expression, false otherwise.
 */
bool findRedundantBrackets(string &s) {
  int n = s.length();
  stack<char> st;

  for (int i = 0; i < n; i++) {
    char ch = s[i];

    if (isOperator(ch) || ch == '(')
      st.push(ch);

    else {
      bool isRedundant = true;
      if (ch == ')') {
        char top = st.top();
        while (top != '(') {
          st.pop();

          if (isOperator(top))
            isRedundant = false;

          top = st.top();
        }
        if (isRedundant == true)
          return true;
        st.pop();
      }
    }
  }
  return false;
}
