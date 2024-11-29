#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int p, int q, int r);

void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[q + j + 1];
    }

    int i = 0, j = 0, k = p;

    while (i < n1 and j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}