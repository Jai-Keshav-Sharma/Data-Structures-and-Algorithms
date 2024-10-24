#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/**
 * @brief Replaces all spaces in the given string with the sequence "@40".
 * 
 * This function iterates through the input string and replaces each space character
 * with the sequence "@40". It modifies the string in place and returns the modified string.
 * 
 * @param str The input string to be modified. It is passed by reference.
 * @return The modified string with spaces replaced by "@40".
 */
string replaceSpaces(string &str)
{

    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            int first = i;
            str[first] = '@';

            int second = i + 1;
            str[second] = '4';

            int third = i + 2;
            str[third] = '0';
        }
        else
        {
            continue;
        }
    }

    return str;
}

int main()
{
    string str;
    getline(cin, str);
    cout << replaceSpaces(str) << endl;
    return 0;
}