#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    
    int cnt = 0;
    for(int i = s + 1; i <= e; i++)
    {
        if(arr[i] <= pivot)
            cnt++;
    }
    
    int pivotIndex = s + cnt;
    swap(arr[s] , arr[pivotIndex]);
    
    int i = s, j = e;
    while(i < pivotIndex and j > pivotIndex)
    {
        while(arr[i] <= pivot)
            i++;
            
        while(arr[j] > pivot)
            j--;
            
        if(i < pivotIndex and j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
    
}

void quickSort(int arr[], int s, int e)
{
    if(s < e)
    {
        int q = partition(arr, s, e);
        quickSort(arr, s, q - 1);
        quickSort(arr, q + 1, e);
    }
}

int main()
{
    int arr[5] = {3, 2, 6, 4, 1};
    quickSort(arr, 0, 4);
    
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}