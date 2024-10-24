#include <bits/stdc++.h>
using namespace std;

int sqrtInt(int x)
{
    int s = 0;
    int e = x;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        int square = mid * mid;
        if (square == x)
        {
            return mid;
        }
        else if (square < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (square > x)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int x, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < x; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int x = 39;
    int tempSol = sqrtInt(x);
    double res = morePrecision(x, 3, tempSol);
    cout << res;
    return 0;
}
