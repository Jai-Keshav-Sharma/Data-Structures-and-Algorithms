// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    vector<int> count(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        res[--count[arr[i]]] = arr[i];
        // count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }
}

int main()
{
    // Write C++ code here
    vector<int> arr = {4, 3, 12, 1, 5, 5, 3, 9};

    // Output array
    // vector<int> outputArray = countSort(inputArray);

    countSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}