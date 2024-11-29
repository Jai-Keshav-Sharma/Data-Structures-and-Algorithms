#include <bits/stdc++.h>
using namespace std;

int main()
{
    //initialising an integer

    // int * ptr = new int;
    // *ptr = 10;
    // cout << *ptr << endl;


    //initialising an array of integers
    int n;
    cin  >> n;
    int * arr= new int[5];
    for (int i = 0; i < n; i++)
    {
        i[arr] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << i[arr] << " ";
    }

    //freeing the memory
    // delete ptr;
    delete [] arr;
    


    return 0;
}