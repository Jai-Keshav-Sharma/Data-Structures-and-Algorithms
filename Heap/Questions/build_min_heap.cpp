#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Converts a subtree rooted with node i into a min-heap.
 *
 * This function assumes that the binary trees rooted at left and right children of node i
 * are already min-heaps. It ensures that the subtree rooted at node i becomes a min-heap.
 *
 * @param arr The array representation of the heap.
 * @param size The size of the heap.
 * @param i The index of the root node of the subtree to be heapified.
 */
void solve(vector<int> &arr, int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size and arr[left] < arr[smallest])
        smallest = left;
    if (right < size and arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        solve(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
    {
        solve(arr, arr.size(), i);
    }
    return arr;
}
