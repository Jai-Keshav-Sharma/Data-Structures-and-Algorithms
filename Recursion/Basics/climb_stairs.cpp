#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the number of distinct ways to climb a staircase with n steps.
 * 
 * This function uses recursion to determine the number of distinct ways to climb
 * a staircase where you can take either 1 step or 2 steps at a time.
 * 
 * @param n The total number of steps in the staircase.
 * @return int The number of distinct ways to climb the staircase.
 *         - Returns 1 if n is 0 (base case: one way to stay at the ground).
 *         - Returns 0 if n is negative (base case: no way to climb a negative number of steps).
 *         - Otherwise, returns the sum of the number of ways to climb (n-1) steps and (n-2) steps.
 */
int distinctWaysToClimb(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    return distinctWaysToClimb(n - 1) + distinctWaysToClimb(n - 2);
}

int main()
{
    int n = 3;
    cout << distinctWaysToClimb(n);

    return 0;
}