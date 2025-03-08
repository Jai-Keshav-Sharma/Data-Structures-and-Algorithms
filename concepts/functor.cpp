#include <bits/stdc++.h>
using namespace std;

class functor
{
public:
    /**
     * @brief Functor (function object) that takes an integer and prints a message.
     * 
     * This operator() function allows an object of the class to be used as if it were a function.
     * It takes an integer as a parameter and prints a message including that integer.
     * 
     * @param n The integer to be printed in the message.
     */
    void operator()(int n)
    {
        cout << "i am " << n;
    }
};

int main()
{
    functor f;
    f(10);

    return 0;
}