#include <stdio.h>
#include <stdarg.h>

int average(int count, ...)
{
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++)
    {
        total = total + va_arg(args, int);
    }

    va_end(args);
    return total / count;
}

int main()
{
    printf("%d", average(3, 4, 2, 3));

    return 0;
}

// Macros used in this program:
// va_list: A type to hold information about variable arguments
// va_start: A macro to initialize a va_list variable
// va_arg: A macro to retrieve the next argument in the parameter list of the function
// va_end: A macro to clean up the va_list variable

// The stdarg.h header file provides facilities for stepping through a list of function arguments of unknown number and type.


#include <stdio.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++)
    {
        total = total + va_arg(args, int);
    }

    va_end(args);

    return total;

}

int main()
{
    
    return 0;
}