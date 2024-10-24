/*Problem statement
 You are given a string 'S'. Your task is to check whether the string is 
 palindrome or not. For checking palindrome, consider alphabets and numbers
 only and ignore the symbols and whitespaces.
Note :

String 'S' is NOT case sensitive. 
*/




#include <bits/stdc++.h>
using namespace std;

bool isValid(string s, int i)
{
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= '0' && s[i] <= '9'))
    {
        return true;
    }
    return false;
}

bool checkPalindrome(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int n = s.length();
    int st = 0;
    int e = n - 1;

    while (st < e)
    {
        if (isValid(s, st) && isValid(s, e))
        {
            if (s[st] == s[e])
            {
                st++;
                e--;
            }
            else
            {
                return false;
            }
        }

        else if (!isValid(s, st))
        {
            st++;
        }
        else if (!isValid(s, e))
        {
            e--;
        }
    }
    return true;
}