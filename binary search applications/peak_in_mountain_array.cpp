#include <bits/stdc++.h>
using namespace std;

int peakInMountainArray(vector<int> nums)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e) //important s < e
    {
        if (nums[mid] < nums[mid + 1])
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
    vector<int> nums = {3, 4, 5, 1};
    int n = nums.size();

    cout << peakInMountainArray(nums);
    return 0;
}