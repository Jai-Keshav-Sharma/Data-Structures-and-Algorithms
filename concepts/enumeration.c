#include <stdio.h>
int main()
{
    enum days
    {
        Sun,
        Mon,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat
    }; // values are automatically asigned by the compiler from 0 onwards
    enum state
    {
        working = 1,
        failed = 0,
        freezed = -1
    };
    enum bool
    {
        True = 1,
        False
    } logical; // to every unassigned variable, a value = previous value  + 1 is automatically assigned
               // False = 1
    // declaring an enum variable
    enum days day;
    day = Thu;

    printf("%d\n", day);

    for (int i = Sun; i <= Sat; i++)
        printf("%d  ", i);

    // another way of declaring an enum variable
    enum state st = freezed;
    printf("\n%d\n", st);

    logical = False;
    printf("%d\n", logical);

    return 0;
}