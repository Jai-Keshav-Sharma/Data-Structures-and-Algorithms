// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int getmax(vector<int> &arr, int n)
{
    int maxi = 0;
    for(int i = 0; i< n; i++)
    {
        maxi = max(arr[i], maxi);
    }
    return maxi;
}

void countSort(vector<int> &arr, int n, int pos);

void radixSort(vector<int> &arr, int n)
{
    int max = getmax(arr, n);
    for(int pos = 1; max/pos > 0; pos = pos*10)
    {
        countSort(arr, n, pos);
    }
}

void countSort(vector<int> &arr, int n, int pos)
{
    vector<int> count(10, 0);
    for(int i = 0; i < n ; i++)
    {
        count[(arr[i]/pos) % 10]++;
    }
    
    for(int i = 1; i < 10;i++)
    {
        count[i] += count[i - 1];
    }
    
    vector<int> res(n);
    for(int i = n - 1; i>= 0; i--)
    {
        res[--count[(arr[i]/ pos) % 10]] = arr[i];
    }
    
    
    for(int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }
}

int main() {
    // Write C++ code here
    vector<int> arr = {4, 3, 12, 1, 5, 5, 3, 9};

    // Output array
    // vector<int> outputArray = countSort(inputArray);

    radixSort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}