#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> nums)
{
    int n = nums.size();
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

int main()
{
    vector<int> nums = {10, 17, 1, 3, 8};
    cout << "pivot is at index: " << pivot(nums) << endl;
    return 0;
}