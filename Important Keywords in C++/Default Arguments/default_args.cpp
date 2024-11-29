#include <bits/stdc++.h>
using namespace std;

/*
    1. Default arguments are used to provide default values to the parameters.
    2. Default arguments are used to avoid the error of missing arguments.
    3. defaulr arguments must be declared from the righmost parameter to the leftmost parameter.
*/

void print(int a, int b = 10, int c = 20)
{
    cout << a << " " << b << " " << c << endl;
}

// void print(int a, int b = 10, int c)  -------> This is wrong. Read point 3.
// {
//     cout << a << " " << b << " " << c << endl;
// }



int main()
{
    print(1);


    return 0;
}