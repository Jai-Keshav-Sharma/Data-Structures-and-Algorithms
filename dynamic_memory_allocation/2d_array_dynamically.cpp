#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];

    // creating a 2D array
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // taking inputs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // outpur
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    // deleting the 2D array
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}