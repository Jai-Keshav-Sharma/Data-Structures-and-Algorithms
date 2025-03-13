#include <bits/stdc++.h>
using namespace std;

void revString(string &s, int i, int j)
{
    if (i > j)
    {
        return;
    }
    swap(s[i++], s[j--]);
    revString(s, i, j);
}

int main()
{
    string s = "Hello";
    revString(s, 0, s.length() - 1);
    cout << s;  // Output: olleH

    return 0;
}