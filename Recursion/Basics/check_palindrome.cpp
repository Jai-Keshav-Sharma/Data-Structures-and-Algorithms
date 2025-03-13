#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j)
{
    if(i > j)
    {
        return true;
    }
    if(s[i] == s[j])
    {
        return isPalindrome(s, i + 1, j - 1);
    }
    else if(s[i] != s[j])
    {
        return false;
    }
}

int main()
{
    string s = "racecar";
    if(isPalindrome(s, 0, s.length() - 1))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not a palindrome";
    }


    return 0;
}