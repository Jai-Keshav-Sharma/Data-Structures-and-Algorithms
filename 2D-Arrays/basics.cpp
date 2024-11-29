#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][3], int target)
{
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            if (arr[rows][cols] == target)
            {
                return true;
            }
        }
    }
    return false;
}

void rowWiseSum(int arr[][3])
{
    for (int rows = 0; rows < 3; rows++)
    {
        int sum = 0;
        for (int cols = 0; cols < 3; cols++)
        {
            sum += arr[rows][cols];
        }
        cout << "Sum of row " << rows << " is " << sum << endl;
    }
}

void columnWiseSum(int arr[][3])
{
    for (int cols = 0; cols < 3; cols++)
    {
        int sum = 0;
        for (int rows = 0; rows < 3; rows++)
        {
            sum += arr[rows][cols];
        }
        cout << "Sum of column " << cols << " is " << sum << endl;
    }
}

void rowWiseLargest(int arr[][3])
{

    for (int rows = 0; rows < 3; rows++)
    {
        int largest = INT_MIN;
        for (int cols = 0; cols < 3; cols++)
        {
            largest = max(largest, arr[rows][cols]);
        }
        cout << "Largest element of row " << rows << " is " << largest << endl;
    }
}

int largestRowSum(int arr[][3])
{   
    int maxi = INT_MIN;
    int rowInd = -1;
    for (int i = 0; i < 3; i++)
    {   
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowInd = i;
        }
        
    }
    cout << "maximum sum is " << maxi << endl;
    return rowInd;
}

int main()
{
    int arr[3][3];

    // row wise input
    // for (int rows = 0; rows < 3; rows++)
    // {
    //     for (int cols = 0; cols < 3; cols++)
    //     {
    //         cin >> arr[rows][cols];
    //     }
    // }

    // column wise input
    for (int cols = 0; cols < 3; cols++)
    {
        for (int rows = 0; rows < 3; rows++)
        {
            cin >> arr[rows][cols];
        }
    }

    // print array
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            cout << arr[rows][cols] << " ";
        }
        cout << endl;
    }

    // isPresent
    // if (isPresent(arr, 3))
    // {
    //     cout << "found" << endl;
    // }
    // else
    // {
    //     cout << "not found" << endl;
    // }

    // rowWiseSum
    //  rowWiseSum(arr);

    // rowWiseLargest
    // rowWiseLargest(arr);

    //largestRowSum
    cout << largestRowSum(arr) << endl;

    return 0;
}