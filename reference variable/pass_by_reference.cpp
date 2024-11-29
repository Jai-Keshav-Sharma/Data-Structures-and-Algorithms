#include <bits/stdc++.h>
using namespace std;

void update(int &n)
{
    n = n + 1;
}

int main()
{
    int n = 5;

    cout << "before: " << n << endl;
    update(n);
    cout << "after: " << n << endl;

        return 0;
}