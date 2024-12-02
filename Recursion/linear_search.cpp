#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if a given element is present in the array using recursion.
 * 
 * This function performs a linear search on the array to determine if the 
 * specified element exists within it. It uses a recursive approach to 
 * traverse the array.
 * 
 * @param arr The array in which to search for the element.
 * @param n The number of elements in the array.
 * @param x The element to search for in the array.
 * @return true if the element is found in the array, false otherwise.
 */
bool isPresent(int arr[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == x)
    {
        return true;
    }
    bool remPart = isPresent(arr + 1, n - 1, x);
    return remPart;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    if (isPresent(arr, n, x))
    {
        cout << "Present";
    }
    else
    {
        cout << "Not present";
    }

    return 0;
}