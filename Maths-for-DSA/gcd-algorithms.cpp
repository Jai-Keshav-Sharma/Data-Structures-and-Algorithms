#include <bits/stdc++.h>
using namespace std;

// // Euclidean recursive
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Euclidean non-recursive
int gcd(int a, int b)
{
    while (b)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}

// normal non- recursive
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    if (
        b == 0)
    {
        return a;
    }

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        if (b > a)
        {
            b = b - a;
        }
    }
    return a;
}