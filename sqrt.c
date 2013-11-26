#include <stdio.h>

#define EPSILON 0.001

int main()
{
    // reference result
    // sqrt(1000) = 31,622776601683793319988935444327

    float prev, next;
    next = 1000;

    do
    {
        prev = next;
        next = (prev + 1000/prev)/2;
    }
    while (prev - next > EPSILON);

    printf("sqrt(1000) = %.6f\n", next);

    return 0;
}
