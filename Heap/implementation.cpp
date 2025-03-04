#include <bits/stdc++.h>
using namespace std;

class Heap
{
    int arr[100];
    int size;

public:
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // inserting into MAX-HEAP
    void insert(int data)
    {
        size = size + 1;
        int index = size;

        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // deleting from MAX-HEAP
    void deleteMax_Heap()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete!" << endl;
            return;
        }

        // step-1
        arr[1] = arr[size];

        // step-2
        size--;

        // step-3
        int i = 1;
        while (i <= size)
        {
            int leftInd = 2 * i;
            int rightInd = 2 * i + 1;

            if (leftInd <= size && arr[leftInd] > arr[i])
            {
                swap(arr[leftInd], arr[i]);
            }
            else if (rightInd <= size && arr[rightInd] > arr[i])
            {
                swap(arr[rightInd], arr[i]);
            }
            else
            {
                return;
            }
        }
    }

    // Printing the HEAP
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

// MAX-HEAPIFY
void max_heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (largest <= size && arr[largest] < arr[left])
        largest = left;

    if (right <= size && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, size, largest);
    }
}

int main()
{
    // Heap h;
    // h.insert(10);
    // h.insert(20);
    // h.insert(30);
    // h.insert(25);
    // h.insert(45);

    // h.print();

    // cout << endl << "deleting: " << endl;
    // h.deleteMax_Heap();

    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = sizeof(arr) / sizeof(arr[0]) - 1;

    for(int i = size / 2; i > 0; i--) {
        max_heapify(arr, size, i);
    }

    cout << endl << "printing the max_heap: " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}