#include <bits/stdc++.h>
using namespace std;

#define ELE 1, \
            2, \
            3

/*
    1. Object like macros:
        #define PI 3.14
    
    2. Chain of macros:
        #define PI 3.14
        #define INSTAGRAM FOLOLOWERS
        #define FOLLOWERS 1000

    3. Function like macros:
        #define min(a, b) ((a < b) ? a : b)

    4. Multiline macros:
        #define ELE 1, /
                    2, /
                    3   
*/

int main()
{
    vector<int> v = {ELE};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }


    return 0;
}