#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    k = s;
    int i = 0, j = 0;
    while (i < len1 and j < len2)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < len1)
    {
        arr[k++] = left[i++];
    }
    while (j < len2)
    {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int *arr, int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, e);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}