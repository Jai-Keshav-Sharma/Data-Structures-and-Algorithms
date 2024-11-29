#include <bits/stdc++.h>
using namespace std;


/*
    1. Inline Functions are used to reduce the function call overhead.
    2. Inline functions are expanded at the time of function call.
    3. Inline functions are used to reduce the execution time.
    4. Inline functions are used to reduce the memory overhead.
    5. function body must contain only one line to be decrlared as inline.
*/

inline int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int a = 10, b = 20;
    cout << min(a, b);


    return 0;
}