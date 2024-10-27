// Given a string str of lowercase alphabets. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

#include <bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(string s)
{
    int n = s.length();

    int arr[26] = {0};

    for (int i = 0; i < n; i++)
    {
        char ch;
        ch = s[i];
        int number = ch - 'a';

        arr[number]++;
    }

    int maxi = -1;
    int ans = -1;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxi)
        {
            ans = i;
            maxi = arr[i];
        }
    }

    int finalAns = ans + 'a';
    return finalAns;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << getMaxOccuringChar(str) << endl;
    }
}