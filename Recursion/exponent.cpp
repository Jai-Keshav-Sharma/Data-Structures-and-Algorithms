#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the power of a number using recursion.
 * 
 * This function calculates a raised to the power of b (a^b) using a recursive approach.
 * It optimizes the calculation by reducing the number of multiplications using the property:
 * - a^b = (a^(b/2))^2 if b is even
 * - a^b = (a^(b/2))^2 * a if b is odd
 * 
 * @param a The base number.
 * @param b The exponent.
 * @return int The result of a raised to the power of b.
 */
int power(int a, int b)
{
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    int ans = power(a, b / 2);

    if (b % 2 == 0)
        return ans * ans;
    else
        return ans * ans * a;
}

int main()
{
    int a = 2, b = 10;
    cout << power(a, b); // Output: 1024

    return 0;
}