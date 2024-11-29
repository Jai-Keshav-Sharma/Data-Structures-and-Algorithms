#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    return (int)log10(n) + 1;
}

int karatsuba(int x, int y)
{
    if(x < 10 || y < 10)
    {
        return x * y;
    }

    int n = max(countDigits(x), countDigits(y));
    int m = n/2;

    long long a = x / (long long)pow(10, m);
    long long b = x % (long long)pow(10, m);
    long long c = y / (long long)pow(10, m);
    long long d = y % (long long)pow(10, m);

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long bc_ad = karatsuba(a + b, c + d) - ac - bd;

    return ac * pow(10, 2* m) + bc_ad * pow(10, 2 * m) + bd;
}

int main()
{
    int x, y;
        cin >> x >> y;
        cout << karatsuba(x, y);


    return 0;
}