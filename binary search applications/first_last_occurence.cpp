// we can also find first and last occurence of an element in an array using binary search
/*
the approach is to first find the leftmost occurence of the key and then the rightmost occurence

it is done by storing the index in 'ans' variable and then itertate again in left side by setting the value of end = mid - 1 to find the leftmost occ.
and similarly setting the value of start = mid + 1 in case of last occ.
*/


/*
total occurences can also be found by lastOcc - firstOcc + 1.
*/

#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    int arr[6] = {5, 7, 7, 8, 8, 10};
    pair<int, int> p;
    p.first = firstOcc(arr, 6, 8);
    p.second = lastOcc(arr, 6, 8);

    cout << p.first << p.second << endl;

    return 0;
}