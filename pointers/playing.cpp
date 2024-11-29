#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int arr[10] = {0};

    // int *p = arr;
    // cout << p << endl;
    // cout << *p << endl;
    // cout << arr << endl;
    // cout << &p << endl;

    // cout << sizeof(p) << endl;
    // cout << sizeof(arr) << endl;

    // int first = 10;
    // int *p = &first;
    // int *q = p;

    // cout << *q << endl;
    // cout << *p << endl;
    // cout << q << endl;
    // cout << p << endl;
    // cout << &first<< endl;

    int first = 10;
    int *p = &first;

    cout << (*p)++ << endl;
    cout << first << endl;
    return 0;
}