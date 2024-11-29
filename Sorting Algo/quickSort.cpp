#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int p, int r);

void quickSort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;

    for(int j = p; j < r ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;

}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}