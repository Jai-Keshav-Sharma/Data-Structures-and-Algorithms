#include <bits/stdc++.h>
using namespace std;

int &update(int &i)
{
    i = i + 1;
    int &ans = i;
    return ans;
}

int main()
{
    int i = 10;

    cout << "before: " << i << endl;

    cout << "after: " << update(i) << endl;

    return 0;
}