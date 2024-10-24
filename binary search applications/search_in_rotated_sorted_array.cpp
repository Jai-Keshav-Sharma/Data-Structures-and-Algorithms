#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> nums, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (nums[mid] >= nums[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int BinarySearch(vector<int> nums, int s, int e, int key)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == key)
            return mid;
        if (nums[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int n = nums.size();
    int target = 3;
    int res;
    int pivot_index = pivot(nums, n);
    // cout << pivot_index << endl;
    if (target >= nums[pivot_index] && target <= nums[n - 1])
    {
        res = BinarySearch(nums, pivot_index, n - 1, target);
    }
    else
    {
        res = BinarySearch(nums, 0, pivot_index - 1, target);
    }
    cout << res;

    return 0;
}