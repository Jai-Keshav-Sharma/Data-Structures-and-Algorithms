#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Main function to demonstrate dynamic memory allocation for a jagged array.
 *
 * This program performs the following steps:
 * 1. Reads an integer 'n' from the standard input.
 * 2. Dynamically allocates a 2D jagged array with 'n' rows, where the i-th row has (i+1) columns.
 * 3. Reads elements into the jagged array from the standard input.
 * 4. Prints the elements of the jagged array.
 * 5. Deallocates the memory used by the jagged array.
 *
 * @return int Returns 0 upon successful execution.
 */

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}