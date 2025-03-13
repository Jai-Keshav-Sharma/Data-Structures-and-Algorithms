#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively prints the digits of a number in words.
 * 
 * This function takes an integer `n` and an array of strings `s` where each index
 * corresponds to the word representation of the digit (0-9). It recursively processes
 * each digit of the number from least significant to most significant and prints
 * the word representation of each digit.
 * 
 * @param n The integer number whose digits are to be printed in words.
 * @param s An array of strings where each index corresponds to the word representation of the digit (0-9).
 */
void sayDigits(int n, string s[])
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n /= 10;

    sayDigits(n, s);
    cout << s[digit] << " ";
}

int main()
{
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigits(412, s);

    return 0;
}